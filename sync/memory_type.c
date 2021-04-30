#include <stdio.h>
#include <string.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(num)        \
   (num & 0x0080 ? '1' : '0'),     \
       (num & 0x0040 ? '1' : '0'), \
       (num & 0x0020 ? '1' : '0'), \
       (num & 0x0010 ? '1' : '0'), \
       (num & 0x0008 ? '1' : '0'), \
       (num & 0x0004 ? '1' : '0'), \
       (num & 0x0002 ? '1' : '0'), \
       (num & 0x0001 ? '1' : '0')

void print_binary(char data)
{
   printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(data));
}

struct my_type
{
   int x;
   long y;
   char name[3];
};

int integer_value;
int long long_value;
struct my_type my;
char *buffer;

int main()
{
   int i;

   integer_value = 5;
   buffer = &integer_value;

   printf("Displaying an integer in memory\n");
   for (i = sizeof(int) - 1; i >= 0; i--)
   {
      print_binary(buffer[i]);
   }
   printf("\n\n");

   long_value = 7;
   buffer = &long_value;

   printf("Displaying a long in memory\n");
   for (i = sizeof(long) - 1; i >= 0; i--)
   {
      print_binary(buffer[i]);
   }
   printf("\n\n");

   my.x = 2;
   my.y = 127;
   strcpy(my.name, "Hello\0");

   buffer = &my;
   printf("Displaying a my_type in memory\n");
   for (i = sizeof(struct my_type) - 1; i >= 0; i--)
   {
      print_binary(buffer[i]);
   }
   printf("\n");

   return 0;
}
