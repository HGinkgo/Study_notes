# 第八章 数组 

------

## 本章主要内容

<img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808115115305.png" alt="image-20250808115115305" style="zoom:80%;" />  

 <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808115202967.png" alt="image-20250808115202967" style="zoom:80%;" /> 

  <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\20201221103650.png" alt="1" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch08\images\20201221103801.png" alt="2" style="zoom:80%;" /> 

------

## 笔记

1. **数组名的值是一个指针常量，指向内存中数组的起始位置**。程序经过编译、链接，链接完成后内存中数组的位置就是固定的，当程序运行时不可移动数组，即不可再修改数组名这个常量值。

2. 数组名做`sizeof`操作符、左`&`的操作数时不以指针常量来表示。其中，`sizeof`返回整个数组的长度，而不是指向数组的指针长度。取址符将产生一个指向数组的指针，而不是指向某个常量值的指针。

3. 除优先级外，下标引用和间接访问完全相同。负值作为数组下标，从指针间接访问方面很好理解。`2[array] = *(2 + (array))`。

4. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808125525654.png" alt="image-20250808125525654" style="zoom:80%;" /> 

   <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808125541916.png" alt="image-20250808125541916" style="zoom:80%;" /> 

5. `8.1.4节`，层层优化一个简单的数组拷贝程序，让`C`语言的代码真正可以和汇编代码媲美！使用指针，优化掉计数器，使用寄存器...NP！一些结论：

   <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808123705258.png" alt="image-20250808123705258" style="zoom:80%;" /> 

6. 数组和指针。声明定长数组，编译器会为数组元素保留内存空间，然后创建数组，数组名为常量指针，指向这段空间的起始地址。而声明一个指针变量，编译器只为指针变量保存空间，不为其指向的任何值分配空间，且指针变量未被初始化指向任何的内存空间。`P150` 精华。

   <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808124413166.png" alt="image-20250808124413166" style="zoom:80%;" /> 

7. 所有的参数都是通过 **传值方式** 传递的，数组的传值调用行为是传递给函数的是参数的一份拷贝，即指向数组起始位置的指针的拷贝，函数可以自由地操作其形参指针而不用担心修改对应的作为实参的指针。`const`在函数参数中的灵活运用。

8. 数组形参只是传递的指向数组第一个元素的指针，函数并不为数组参数分配空间。存储与静态内存的数组只初始化一次，默认初始化值为 0。局部变量由于在堆栈上，内存并不相同，在缺省情况下是未初始化的，若在声明中给出了初始值，其实是以一条隐式的赋值语句来初始化。

9. 当数组的初始化局部于一个函数（或代码块）时，你应该仔细考虑一下，在程序的执行流每次进入该函数（或代码块）时，每次都对数组进行重新初始化是不是值得。如果答案是否定的，你就把数组声明为`static`，这样数组的初始化只需在程序开始前执行一次。

10. 多维数组和指针的联系。一维数组名是 **指向元素类型的指针**，多维数组以低维数组做元素，即 `a[3][10]`，其数组名是一个指向一个包含 10 个整形元素的数组的指针。

    <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808123945012.png" alt="image-20250808123945012" style="zoom:80%;" />  

11. 下标引用的优先级高于间接访问。数组指针和指针数组的区别：指针指向数组，数组内元素是指针。

12. 指针数组。`int *a[10]`，下标引用优先级高于间接访问，故在此先执行下标引用，故 `a` 是某类型的数组，取得数组元素后随即执行间接访问，那么这个元素就是个指针，最终的结果是一个整型值。故`a`中的元素类型就是指向整形的指针。这点经常在 **字符串指针数组** 中常用。

------

## 课后习题

1. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808125103730.png" alt="image-20250808125103730" style="zoom:80%;" /> 

   <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808125130363.png" alt="image-20250808125130363" style="zoom:80%;" /> 

   答：`ints[-2]`搞错了。

   <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808125657661.png" alt="image-20250808125657661" style="zoom:80%;" /> 

2. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808125756293.png" alt="image-20250808125756293" style="zoom:80%;" /> 

   答：运算符优先级不同。第二个等价于`array[j] + i`。

3.  <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808125922737.png" alt="image-20250808125922737" style="zoom:80%;" /> 

   答：不能。因为指针指向数组左边界的前一个位置了，数组越界，赋值是非法的。

4. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808130026632.png" alt="image-20250808130026632" style="zoom:80%;" /> 

   答：

   <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\20201221104742.png" alt="4" style="zoom: 80%;" /> 

5. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808130320434.png" alt="image-20250808130320434" style="zoom:80%;" /> 

   答：书上讲过类似的问题，在一步一步优化程序那一部分。修改为指=指针所提升的效率不是那么有效的时候，没那么有必要修改为指针。

   <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\20201221104921.png" alt="5" style="zoom:80%;" /> 

6. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808130530130.png" alt="image-20250808130530130" style="zoom:80%;" /> 

   答：书上讲解的很清楚了，关于汇编不做实验了。

7. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808130635367.png" alt="image-20250808130635367" style="zoom:80%;" /> 

   答：和机器性能及编译器都有关。关于及时可以使用相关库函数。

8. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808130712831.png" alt="image-20250808130712831" style="zoom:80%;" /> 

   答：贴个标准答案。

   <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\20201221113046.png" alt="6" style="zoom:80%;" /> 

   > **警告！！！重点坑点！！！**
   >
   > **第一个赋值中**。答案给的解释看不懂，甚至一度认为这样的写法是正确的。有一说一，答案给的解释是真不行！这个问题应该归结到 `extern` 数组与 `extern` 指针中去。如果在 `main` 文件中使用 `extern char *data`，编译不会出错，先让 `char data[100] = {10};`，然后打印 `data` 的值是 10， 所以猜测 `main` 文件中 `data` 的值是 `test` 文件 `data` 指针指向地址内容，继续验证让 `char data[100] = {0, 0, 0, 0，1};`，打印的值是 0，再让 `char data[100] = {0, 0, 0，1};`，打印的值是 16777216（就是小端模式下的 0x1000000)，所以引用方式是错误，**编译器把数组的内容解释为指针值（地址）**，只取数组的前4个字节（32位模式）。应该保持类型匹配，使用 `extern char data[]`，编译器就会把 `data` 值设置为数组首地址。**第二个赋值中。** 编译器认为 `b` 是个数组名，故将 12 加到 `b` 的存储地址，然后间接访问获取值。然而 `b` 只是一个指针变量，**它的存储位置和数组的起始位置没有任何关系**，从内存中提取到后面的 3 个整形位置实际上是从任意变量中取得的，并非从数组的首地址开始向后偏移 3 个整形大小取到数组的第三个元素。所以都是未知，随机的。**很不错的一个问题！** 

   上面是一个博主的评价，当然我的好多答案都是照抄博主的，笑死。

   这段话是在解释一个**经典的 C 语言陷阱**：**`extern` 声明时，把数组当成指针用，或者把指针当成数组用，会导致未定义行为（UB）**。**编译器不会检查 `extern` 的类型是否匹配，而是直接按你声明的类型去解释内存，结果必然出错。**

   **源文件1** 定义的是：

   ```c
   int a[10];  // 数组
   int *b = a; // 指针指向数组首地址
   ```

   **源文件2** 却声明为：

   ```
   extern int *a; // 把数组当成指针用！
   extern int b[]; // 把指针当成数组用！
   ```

   **错误原因**：

   - 在源文件2中，`a` 被当成 **指针变量**，但实际上在源文件1中 `a` 是 **数组名**（编译器会直接替换为数组首地址）。
   - 当执行 `x = a[3]` 时，编译器会：
     1. 从 `a` 的内存地址（即数组首地址）**读取前4字节**（因为 `int*` 是4字节）。
     2. 把这4字节内容当成 **指针值**（地址），而不是数组元素。
     3. 再从这个“假地址”偏移12字节（`3 * sizeof(int)`）取值，结果必然是**野值**。

   **第二个赋值 `y = b[3]` 的问题**

   - 在源文件1中，`b` 是 **指针变量**（存储在栈上的独立变量），它的值是数组首地址。
   - 但在源文件2中，`b` 被声明为 `extern int b[];`，即当成 **数组名** 用。
   - 执行 `y = b[3]` 时，编译器会：
     1. 把 `b` 当成数组首地址（即 `b` 这个变量的**存储地址**，而非它指向的地址）。
     2. 从 `b` 的存储地址偏移12字节取值，但这块内存根本不是数组，而是**其他变量的数据**，结果随机。

9. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808132804826.png" alt="image-20250808132804826" style="zoom: 80%;" /> 

   答：`int coin_values[] = { 1, 5, 10, 25, 50, 100 };`

10. 问题

    <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808132841048.png" alt="image-20250808132841048" style="zoom:80%;" /> 

    答：<img src="F:\Study_notes\Pointers_on_C\src\ch08\images\20201221114913.png" alt="7" style="zoom:80%;" /> 

    - 内存布局（按行连续）：

      ```
      [0][0], [0][1], [1][0], [1][1], [2][0], [2][1], [3][0], [3][1]
      ```

    - `array[1][2]` 的地址：
      - 虽然 `[1][2]` 看似越界（第 1 行只有 `[0]` 和 `[1]`），但 C 语言**不会检查越界**。
      - 计算：
        `&array[1][2] = 1000 + (1 * 2 + 2) * 2 = 1000 + 4 * 2 = 1008`
    - `array[2][0]` 的地址：
      - 计算：
        `&array[2][0] = 1000 + (2 * 2 + 0) * 2 = 1000 + 4 * 2 = 1008`

11. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808150233001.png" alt="image-20250808150233001" style="zoom: 67%;" />  

    <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808150247746.png" alt="image-20250808150247746" style="zoom:80%;" /> 

    答：

    <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\20201221115502.png" alt="8" style="zoom:80%;" /> 

12. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808150450394.png" alt="image-20250808150450394" style="zoom:80%;" /> 

    答：

    <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808150512238.png" alt="image-20250808150512238" style="zoom:80%;" /> 

13. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808150648407.png" alt="image-20250808150648407" style="zoom:80%;" /> 

    答：![10](F:\Study_notes\Pointers_on_C\src\ch08\images\20201221120107.png)

14. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808151041451.png" alt="image-20250808151041451" style="zoom:80%;" /> 

    答：显然，`i` 声明为整形指针变量的时候不会报错。

15. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808151656901.png" alt="image-20250808151656901" style="zoom:80%;" /> 

    答：第二个有意义啊。双指针算法中经常都是这样，`&&` 有运算符截断的特性，所以前者判断越界后后者就不再进行检查，就避免了越界错误。写在后面...啥也不是。

16. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808151802628.png" alt="image-20250808151802628" style="zoom:80%;" /> 

    答：`array1` 其作为函数参数，实际上是一个指针变量。指向作为实际参数传递的数组，该指针变量的值可以被修改，同时数组作为参数并没有给其分配内存空间。而 `array2` 是指针常量，因此其值不能更改，且在这个函数中给其分配了 10 个整数的空间。

17. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808151903293.png" alt="image-20250808151903293" style="zoom:80%;" /> 

    答：**第一个参数是一个标量**，写不写 `const` 意义都不是很大。对这份拷贝的修改并不会影响原来的参数，`const` 关键字的作用并不是防止原来的参数被修改。第二个参数实际上是一个指向整形的指针，传递给函数的是指针的拷贝，对其进行修改并不会影响到指针参数本身，**但是可以通过该指针执行间接访问来修改指向的值，`const` 关键字在此用于防止这种修改。这种 `const` 关键字的应用是非常广泛的。**

18. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808152039683.png" alt="image-20250808152039683" style="zoom:80%;" /> 

    答：`void function( int array[][2][5] ); void function( int  (*array)[2][5] );`

19. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808152127148.png" alt="image-20250808152127148" style="zoom:80%;" /> 

    答：在其末尾附加一个空串即可。

    `for( kwp = keyword_table; **kwp != '\0'; kwp++ )`

------

## 编程练习

1. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808152223422.png" alt="image-20250808152223422" style="zoom:80%;" /> 

   答：有点逆天，看到答案还真是这样。

   ```
   unsigned char table[3][6][4][5] = {
       { /* 0 */
           { /* 0,0 */
               {0},
           }
       },
       { /* 1 */
           {/* 1,0 */
               {0}
           },
           { /* 1,1 */
               {0},
               {0, ' ' }
           },
           {/* 1,2 */
               {0},
               {0},
               {0, 0, 0, 'A' },
               {0, 0, 0, 0, 'X' }
           },
           {/* 1,3 */
               {0},
               {0},
               {0, 0, 0363}
           },
           {/* 1,4 */
               {0},
               {0},
               {0, 0, 0, '\n' }
           }
       },
       { /* 2 */
           {/* 2,0 */
               {0}
           },
           {/* 2,1 */
               {0},
               {0, 0, 0320}
           },
           {/* 2,2 */
               {0},
               {0, '0' },
               {0, 0, '\'' },
               {0, '\121' }
           },
           {/* 2,3 */
               {0}
           },
           {/* 2,4 */
               {0},
               {0},
               {0},
               {0, 0, '3', 3}
           },
           {/* 2,X */
               {0},
               {0},
               {0},
               {0, 0, 0, 0, '}' }
           }
       },
   };
   ```

2. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808162602787.png" alt="image-20250808162602787" style="zoom:80%;" /> 

   答：本来想用`if-else`解决，但好像这单元讲的是数组。

   ```
   #include <stdio.h>
   #include <float.h>
   
   static double income_list[] = {
       0, 23350, 56550, 117950, 256500, DBL_MAX};
   static double base_tax[] = {
       0, 3502.5, 12798.5, 31832.5, 81710.5};
   static float percentage[] = {
       .15, .28, .31, .36, .396};
   
   double single_tax(double income) {
       int i = 1;
       for (i; income >= income_list[i]; i++)
           ;
       i--;
       return base_tax[i] + percentage[i] * (income - income_list[i]);
   }
   ```

3. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808162808743.png" alt="image-20250808162808743" style="zoom:80%;" /> 

   答：

   ```
   #include <stdio.h>
   
   int identity_matrix(int a[][10]) {
       int i = 0;
       for (int i = 0; i < 10; ++i) 
           if (!a[i][i])
               return 0;
       return 1;
   }
   
   int main() {
       int a[10][10];
       if (identity_matrix(a))
           puts("YES");
       else
           puts("NO");
       return 0;
   }
   ```

4. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808162910286.png" alt="image-20250808162910286" style="zoom:80%;" /> 

   答：多一个参数指定矩阵大小就行。

5. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808163011766.png" alt="image-20250808163011766" style="zoom:80%;" /> 

   答：

   ```
   #include <stdio.h>
   
   void matrix_multiply(int *a, int *b, int *r, int x, int y, int z) {
       int *m1p, *m2p;
       for (int i = 0; i < x; i ++ ) {     // 遍历 a 的行
           for (int j = 0; j < z; j ++) {  // 遍历 b 的列
               m1p = a + i * y;            // 选择 a 矩阵的第 i 行元素。跳过前 i*y 个元素
               m2p = b + j;                // 选择 b 矩阵的第 j 列元素。跳过前 j 个元素即可
               *r = 0;                     // 当前位置清空
               for (int k = 0; k < y; k ++) {  // y 次乘积之和为当前位置元素值大小，
                   *r += *m1p * *m2p;
                   m1p++;                  // 每次加 1 个到下一列
                   m2p += z;               // 每次跳过 z 个到下一行
               }
               r++;                        // 且为行主序遍历，每次 r ++ 即可
           }
       }
   }
   
   
   int main() {
       int a[3][2] = {{2, -6}, {3, 5}, {1, -1}};
       int b[2][4] = {{4, -2, -4, -5}, {-7, -3, 6, 7}};
       int x = 3, y = 2, z = 4;
       int r[x][z];
       matrix_multiply(a, b, r, x, y, z);
   
       for (int i = 0; i < x; i ++) {
           for (int j = 0; j < z; j ++) {
               printf("%d ", r[i][j]);
           }
           puts("");
       }
       return 0;
   }
   
   /*
   50 14 -44 -52
   -23 -21 18 20
   11 1 -10 -12
   */
   ```

6. <img src="F:\Study_notes\Pointers_on_C\src\ch08\images\image-20250808163356421.png" alt="image-20250808163356421" style="zoom:80%;" /> 

   参考：https://blog.csdn.net/yl_puyu/article/details/109256862

   









































