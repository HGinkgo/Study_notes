# 第七章 函数 

------

## 本章主要内容

<img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250805161446808.png" alt="image-20250805161446808" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch07\images\20201227174606.png" alt="1" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch07\images\20201220142925.png" alt="2" style="zoom:80%;" /> 

------

## 笔记

1. `while`循环在循环体每次执行时必须取得某种进展，逐步迫近循环终止条件。递归函数也是如此，它在每次递归调用后必须越来越接近 **某种限制条件**。当递归函数符合这个限制条件时，它便不再调用自身。
2. 尾部递归很容易改写成循环的形式，效率通常会更高一些。



------

## 课后习题答案

1. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806155408325.png" alt="image-20250806155408325" style="zoom:80%;" /> 

   答：可在其内部打印一句话，表示它已被调用。

2. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806155449874.png" alt="image-20250806155449874" style="zoom:80%;" /> 

   答：个人认为是缺点，有了正确的规范学起来更快，当然规范会随着时间不断优化。

   > 它的一个优点是它允许您变得懒惰；可以编写的代码更少。其他的后果，比如能够用错误的参数数或类型调用函数，是所有缺点。

3. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806155709187.png" alt="image-20250806155709187" style="zoom:80%;" /> 

   答：会报错？正确答案：最终值将转换为`A`类型。

4. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806155750527.png" alt="image-20250806155750527" style="zoom:80%;" /> 

   答：`return ;`可以，但是不能`return 表达式;`编译器将报错。

5.  <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806155939081.png" alt="image-20250806155939081" style="zoom:80%;" /> 

   答：返回值将被按照`int`类型进行解释。

6. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806155926459.png" alt="image-20250806155926459" style="zoom:80%;" /> 

   答：将被解释为形参类型，而不是实际类型。

7. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806160011291.png" alt="image-20250806160011291" style="zoom:80%;" /> 

   答：该函数假定了传入进来的数组大小是 10 个元素，如果数组元素大于 10 个，则会忽略后面的元素，如果数组元素小于 10 个，则出现越界访问。事实上就是数组名做了参数，即退化为指针。**且由于`for`循环固定死了为 10 次，这是问题的本质所在。**

8. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806160202668.png" alt="image-20250806160202668" style="zoom:80%;" /> 

   答：都要有终止条件，且不断逼近终止条件。

9. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806160227437.png" alt="image-20250806160227437" style="zoom:80%;" /> 

   答：在多个源文件中使用#include比复制原型更容易。原型本身只有一个副本。在定义函数的文件中包含原型可确保它们匹配。

10. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806160257487.png" alt="image-20250806160257487" style="zoom:80%;" /> 

    答：

    ```
    #include <stdio.h>
    
    int cnt = 0;
    
    long long fib(int n) {
        ++cnt;
        if (n <= 2)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }
    
    
    int main() {
        printf("%d %d\n", cnt, fib(5)); // 9 5
        printf("%d %d\n", fib(5), cnt); // 9 0  printf函数压栈顺序，从右向左
    
    
        printf("%d %d\n", cnt, fib(100)); // 风扇飞起
    }
    ```

    ------



## 编程练习

1. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806182715606.png" alt="image-20250806182715606" style="zoom:80%;" /> 

   答：

   ```
   #include <stdio.h>
   
   long long foo(int n, int x) {
       if (n <= 0)
           return 1;
       if (n == 1)
           return 2 * x;
       return 2 * x * foo(n - 1, x) - 2 * (n - 1) * foo(n - 2, x);
   }
   
   
   int main() {
       printf("%d \n", foo(3, 2));
   }
   ```

2. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806183527991.png" alt="image-20250806183527991" style="zoom:80%;" /> 

   答：

   ```
   #include <stdio.h>
   
   int gcd(int a, int b)
   {
       if (b == 0) {
           return a;
       }
       return gcd(b, a % b);
   }
   
   int main()
   {
       int a, b;
       printf("Enter two integers: ");
       scanf("%d %d", &a, &b);
       
       int result = gcd(a, b);
       printf("GCD of %d and %d is %d\n", a, b, result);
       
       return 0;
   }
   ```

3. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806184524248.png" alt="image-20250806184524248" style="zoom:80%;" /> 

   答：**有点意思，以前字符串转数字没有注意这个用法**

   ```
   #include <stdio.h>
   #include <string.h>
   
   int s2i(char *s) {
       int res = 0;
       while (*s != '\0') {
           res = res * 10 + *s - '0';
           *s++;
       }
       return res;
   }
   
   int main() {
       char *s = "1234";
       printf("%d %d\n", atoi(s), s2i(s));
   }
   ```

4. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806185829534.png" alt="image-20250806185829534" style="zoom:80%;" /> 

   答：

   ```
   #include <stdio.h>
   #include <stdarg.h>
   
   int max_list(int first, ...) {
       va_list var_arg;
       int max = 0;
       if (first >= 0) {
           int this = 0;
           max = first;
           va_start(var_arg, first);
           while ((this = va_arg(var_arg, int)) >= 0)
               if (this > max) 
                   max = this;
           va_end(var_arg);
       }
       return max;
   }
   
   int main() {
       printf("%d\n", max_list(1, 2, 3, 4, 5, 6, -1));
   }
   ```

5. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806190203242.png" alt="image-20250806190203242" style="zoom:80%;" /> 

   答：

   ```
   #include <stdio.h>
   #include <stdarg.h>
   
   void printf(char *format, ...) {
       va_list arg;
       char c;
       char *str;
   
       va_start(arg, format);
   
       while ((c = *format++) != '\0') {
           if (c != '%') {
               putchar(c);
               continue;
           }
           switch (*format != '\0' ? *format ++ : '\0')
           {
           case 'd': 
               print_integer(va_arg(arg, int));
               break;
           case 'f':
               print_float(va_arg(arg, float));
               break;
           case 'c':
               putchar(va_arg(arg, int));
               break;
           case 's':
               str = va_arg(arg, char *);
               while (*str != '\0' )
                   putchar(*str++);
               break;
           }
       }
   }
   
   
   int main() {
       
   }
   ```

6. <img src="F:\Study_notes\Pointers_on_C\src\ch07\images\image-20250806190305016.png" alt="image-20250806190305016" style="zoom:80%;" /> 

   ```
   #include <stdio.h>
   #include <string.h>
   
   /*
   ** Convert a numeric value to words.
   */
   static char *digits[] = {
       "", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ",
       "EIGHT ", "NINE ", "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ",
       "FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",
       "NINETEEN "};
   
   static char *tens[] = {
       "", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", "SEVENTY ",
       "EIGHTY ", "NINETY "};
   
   static char *magnitudes[] = {
       "", "THOUSAND ", "MILLION ", "BILLION "};
   /*
   ** Convert the last 3–digit group of amount to words. Amount is the value
   ** to be converted, buffer is where to put the words, and magnitude is the
   ** name of the 3–digit group we’re working on.
   */
   
   static void do_one_group(unsigned int amount, char *buffer, char **magnitude) {
       int value;
   
   /*
   ** Get all the digits beyond the last three. If we have any value
   ** there, process those digits first. Note that they are in the next
   ** magnitude.
   */
       value = amount / 1000;
       if (value > 0)
           do_one_group(value, buffer, magnitude + 1);         // 处理低三位
   
   /*
   ** Now process this group of digits. Any hundreds?          // 现在处理这组数字。有几百个吗？
   */
       amount %= 1000;                                         // 将数据缩小到 1000 以内
       value = amount / 100;                                   // 处理百位
       if (value > 0) {
           strcat(buffer, digits[value]);
           strcat(buffer, "HUNDRED ");
       }
       /*
   ** Now do the rest of the value. If less than 20, treat it as a single  // 现在执行其余的值。如果少于20个，就当作一个单身数字来得到青少年的名字。
   ** digit to get the teens names.
   */
       value = amount % 100;
       if (value >= 20) {
           /*
   ** Greater than 20. Do a tens name and leave the units to be           // 大于20。做一个十位数的名字，并留下单位下一页打印
   ** printed next.
   */
           strcat(buffer, tens[value / 10]);
           value %= 10;
       }
       if (value > 0)
           strcat(buffer, digits[value]);
       /*
   ** If we had any value in this group at all, print the magnitude.      // 如果我们在这个组中有任何值，打印出数值。
   */
       if (amount > 0)
           strcat(buffer, *magnitude);
   }
   
   
   
   void written_amount(unsigned int amount, char *buffer) {
       if (amount == 0)
           /*
   ** Special case for zero.
   */
           strcpy(buffer, "ZERO ");
       else
       {
           /*
   ** Store an empty string in the buffer, then begin.                 // 在缓冲区中存储一个空字符串，然后开始。
   */
           *buffer = '\0';
           do_one_group(amount, buffer, magnitudes);
       }
   }
   
   int main() {
       char buff[1024];
       do_one_group(16312, buff, magnitudes);
       printf("%s\n", buff);       // ?rSIXTEEN THOUSAND THREE HUNDRED TWELVE          npnp!
       return 0;
   }
   ```

   