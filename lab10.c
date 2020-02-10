/*
 * Name:	Karl Schaller
 * Section: 03
 * Date:	11/24/2019
 * Lab:  	CIS2107_Lab10_BitWiseOperators 
 * Goal: 	Practice with bit operations
 */

#include <stdio.h>
#include <stdint.h>

/* weatherlog_t is a "weather sensor log type"
 which is really defined as a 64-bit unsigned
 integer.  See below. */
typedef uint64_t weatherlog_t;

unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);

void print_half_nybbles(unsigned int);
unsigned int reverse_half_nybbles(unsigned int);

int has_odd(unsigned int);
unsigned int make_odd(unsigned int);

int is_negative(int);

weatherlog_t pack_log_entry(unsigned int, unsigned int, unsigned int,
                            unsigned int,
                            int, int,
                            unsigned int, unsigned int);

unsigned int get_year(weatherlog_t entry);
unsigned int get_month(weatherlog_t entry);
unsigned int get_day(weatherlog_t entry);
unsigned int get_zip(weatherlog_t entry);
unsigned int get_high(weatherlog_t entry);
unsigned int get_low(weatherlog_t entry);
unsigned int get_precip(weatherlog_t entry);
unsigned int get_wind(weatherlog_t entry);

int main(int argc, char **argv) {
    unsigned int i, j;
    int x, y;
    unsigned int year, month, day,
    zip, high_temp, low_temp, precip, avg_wind_speed;
    weatherlog_t log_entry;
    
    printf("Enter an integer: ");
    scanf("%u", &i);
    printf("Enter another integer: ");
    scanf("%u", &j);
    printf("One more integer, please: ");
    scanf("%d", &x);
    printf("Please enter a positive integer: ");
    scanf("%d", &y);
    
    printf("i + j = %u\n", add(i,j));
    printf("i - j = %u\n", sub(i,j));
    printf("i * j = %u\n", mul(i,j));
    
    if (is_negative(x))
        printf("%d is negative\n", x);
    else
        printf("%d is non-negative\n", x);
    
    if (has_odd(y)) {
        printf("%x has an odd number of bits in its binary representation\n", y);
    }
    else {
        printf("%x has an even number of bits in its binary representation\n", y);
        printf("but %x has an odd number of bits in its binary representation\n", make_odd(y));
    }
    
    printf("The half-nybbles of %d (in hex 0x%x) are:", x, x);
    print_half_nybbles(x);
    
    printf("%x with reversed half-nybbles is %x\n", x, reverse_half_nybbles(x));
    print_half_nybbles(reverse_half_nybbles(x));
    
    printf("Enter a year: ");
    scanf("%u", &year);
    
    printf("Enter a month as an integer (1-12): ");
    scanf("%u", &month);
    
    printf("Enter a day as an integer (1-31): ");
    scanf("%u", &day);
    
    printf("Enter a zip code as an integer (0-99999): ");
    scanf("%u", &zip);
    
    printf("Enter a temperature as an integer: ");
    scanf("%u", &high_temp);
    
    printf("Enter another temperature as an integer: ");
    scanf("%u", &low_temp);
    
    
    printf("Enter rainfall amount as an integer (mm): ");
    scanf("%u", &precip);
    
    printf("Enter a as an integer (km/hr): ");
    scanf("%u", &avg_wind_speed);
    
    
    log_entry=pack_log_entry(year, month, day, zip, high_temp, low_temp,
                             precip, avg_wind_speed);
    printf("You entered: %u/%u/%u for zip %5d: high %d F, low %d F, precip %d mm, wind speed %d km/hr\n",
           get_day(log_entry), get_month(log_entry), get_year(log_entry),
           get_zip(log_entry), get_high(log_entry), get_low(log_entry),
           get_precip(log_entry), get_wind(log_entry));
    return 0;
}

unsigned int add(unsigned int i, unsigned int j) {
    /* can be done in a total of 7 lines, including one to declare an unsigned int, */
    /* two for a while loop, and one for the return
     You're not required to do it in 7 lines though . */
    unsigned int carry;
      while (j != 0) { // keep looping while there are things to be added
              carry = (i & j) << 1; // digits with both 1's carried up
              i = i ^ j; // add numbers, ignoring carry
              j = carry; // get ready to add carry on next iteration
      }
      return i;
}

unsigned int sub(unsigned int i, unsigned int j) {
    /* Similar 7 lines, although there is a shorter way */
    return add(i, add(~j, 1)); // add 2's complement
}

unsigned int mul(unsigned int i, unsigned int j) {
    /* can be done in a total of 8 lines including one to declare unsigned ints */
    /* two for a for loop, and one for the return */
    unsigned int product = 0;
    for (unsigned int k = 0; k < j; k = add(k, 1)) // add i together j times
        product = add(product, i);
    return product;
}

/* prints the half-nybbles (i.e. 2 bit values) of x,
 one half-nybble at a time */
void print_half_nybbles(unsigned int x) {
    unsigned int n = mul(8, sizeof(unsigned int));
    while (n) { // print leftmost 2 bits, then continue right
        n = sub(n, 2);
        printf(" %c%c", add('0', (x >> add(n, 1)) & 1), add('0', (x >> n) & 1));
    }
    puts("");
}

/* returns the reverse of the half-nybbles of i */
unsigned int reverse_half_nybbles(unsigned int i) {
    unsigned int n = mul(8, sizeof(unsigned int)), new = 0;
    unsigned int size = n;
    while (n) { // copy leftmost 2 bits to the right end, then continue
        n = sub(n, 2);
        new = new | (((i >> n) & 3) << sub(sub(size, n), 2));
    }
    return new;
}

/* returns 1 if x < 0
 returns 0 otherwise
 
 Do not use the <, > operators. */
int is_negative(int x) {
    return ((x >> sub(mul(8, sizeof(int)), 1)) & 1 == 1); // negative if first bit is 1
}

/* returns 1 if x's binary representation
 has an odd number of 1s or 0 otherwise */
int has_odd(unsigned int x) {
    int n = mul(8, sizeof(unsigned int)), count = 0;
    while (n) { // counts number of 1s
        n = sub(n, 1);
        if (((x >> n) & 1) == 1)
            count = add(count, 1);
    }
    return (count & 1) == 1; // returns if last bit is a 1 (then it's odd)
}

/* If x's binary representation contains an odd number of 1s, x is
 returned. Otherwise, it returns a copy of x, but with its most significant
 bit modified so that there is an odd number of 1s. */
unsigned int make_odd(unsigned int x) {
    if (has_odd(x))
        return x;
    
    return x^(1 << sub(mul(8, sizeof(unsigned int)), 1)); // flips x's leftmost (most significant) bit
}


/* combines all of the arguments into a single weatherlog_t entry as described below */
weatherlog_t pack_log_entry(unsigned int year, unsigned int month, unsigned int day,
                            unsigned int zip, int high_temp, int low_temp,
                            unsigned int precip, unsigned int avg_wind_speed) {
    weatherlog_t log = year; // packs year, the continues while shifting left
    log = log << 4 | month;
    log = log << 5 | day;
    log = log << 16 | zip;
    log = log << 8 | high_temp;
    log = log << 8 | low_temp;
    log = log << 10 | precip;
    log = log << 7 | avg_wind_speed;
    
    /*unsigned int n = mul(8, sizeof(weatherlog_t));
    while (n) {
        n = sub(n, 4);
        printf(" %c%c%c%c", add('0', (log >> add(n, 3)) & 1), add('0', (log >> add(n, 2)) & 1), add('0', (log >> add(n, 1)) & 1), add('0', (log >> n) & 1));
    }
    puts("");*/
    
    return log;
}

unsigned int get_year(weatherlog_t entry) {
    return entry >> 58;
}

unsigned int get_month(weatherlog_t entry) {
    return (entry << 6) >> 60;
}

unsigned int get_day(weatherlog_t entry) {
    return (entry << 10) >> 59;
}

unsigned int get_zip(weatherlog_t entry) {
    return (entry << 15) >> 48;
}

unsigned int get_high(weatherlog_t entry) {
    return (entry << 31) >> 56;
}

unsigned int get_low(weatherlog_t entry) {
    return (entry << 39) >> 56;
}

unsigned int get_precip(weatherlog_t entry) {
    return (entry << 47) >> 54;
}

unsigned int get_wind(weatherlog_t entry) {
    return (entry << 57) >> 57;
}

/* weatherlog_t

A particular weather sensor called the WeatherJuicer 2000 TM stores a
log entry each day, representing weather activity from the
previous 24 hours. Each entry includes a:

- year :: 6 bits -- stored as the number of years since the year 2000.
- month :: 4 bits
- day :: 5 bits
- zip_code :: 16 bits
- high_temp :: in degrees Fahrenheit, stored as an 8-bit signed integer
- low_temp :: in degrees Fahrenheit, stored as 8-bit signed integer
- precipitation :: in mm. stored as a 10-bit unsigned integer.
- average_wind_speed :: 7 bits. unsigned int km/hr.

All of these are packed into a 64 bit unsigned integer in the above order.

For example, if on September 16, 2015, on Temple's main campus, which
is in zip code 19122, we have 15 mm of rain, a high temperature of 85
degrees, a low temperature of 65 degrees, and an average wind speed of
5 km/hour.

We'd store:
- year :: 2015, which is 15 years from 2000, so 001111
- month :: September, which is the 9th month, so 1001.
- day :: 16, which is 1 0000
- zip_code :: 19122 which is 0100 1010 1011 0010
- high_temp :: 85F, so 0101 0101
- low_temp :: 65F, so 0100 0001
- precipitation :: 35 mm so 00 0010 0011
- average wind speed :: 5 km/h, so 000 0101

And all would be packed into a single 64-bit unsigned integer:

00 1111 1001 10000 0100 1010 1011 0010 0101 0101 0100 0001 00 0010 0011 000 0101

OR

0011 1110 0110 0000 1001 0101 0110 0100 1010 1010 1000 0010 0001 0001 1000 0101

OR

0x3e609564aa821185


We define this weather log as its own datatype called weatherlog_t, which
under the covers is really a 64-bit unsigned int. This is done in the line:

typedef uint64_t weatherlog_t;
 
*/