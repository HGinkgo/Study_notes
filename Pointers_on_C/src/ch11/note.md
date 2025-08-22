# 第十一章 动态内存分配 

------

## 本章主要内容

<img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250819190703463.png" alt="image-20250819190703463" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250819190742259.png" alt="image-20250819190742259" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250819190756949.png" alt="image-20250819190756949" style="zoom:80%;" /> 

------

## 笔记

1. `calloc` 也用于分配内存。`malloc` 和 `calloc` 之间的主要区别是后者在返回指向内存的指针之前把它初始化为 0。
2. `realloc` 函数用于修改一个原先已经分配的内存块的大小。如果原先的内存块无法改变大小，`realloc` 将分配另一块正确大小的内存，并把原先那块内存的内容复制到新的块上。
3. 当一个使用动态内存分配的程序失败时，人们很容易把问题的责任推给 `malloc` 和 `free` 函数。但它们实际上很少是罪魁祸首。事实上，问题几乎总是出在你自己的程序中，而且常常是由于访问了分配内存以外的区域而引起的。

------

## 课后习题答案

1. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820131609773.png" alt="image-20250820131609773" style="zoom:80%;" /> 

   答：静态数组：最多 **GB 级**（≈ 2³¹ 字节）就封顶；动态分配：64 位环境下可以 **TB 级**（实际值 ≈ “物理内存 + 交换区” 或 OS 地址空间上限）。

2. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820132557977.png" alt="image-20250820132557977" style="zoom:80%;" /> 

   答：可能有两种解释。请求较小的块可能会允许分配更多的内存，因为最后一次分配后剩余的内存量将更小。这将使较小请求的总数变大。不过，更有可能的是较小的请求越小：这是由于 `malloc` 附加到内存的额外空间的开销，以便跟踪每个分配的块的大小。

3. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820132931429.png" alt="image-20250820132931429" style="zoom:80%;" /> 

   答：问的 `GPT` 说是 `8kb`，太小（512 B、1 KB）→ 系统调用过多，性能差；太大（1 MB、4 MB）→ 内存浪费，甚至触发 `TLB/Cache` 抖动；8 KB 在“带宽 vs. 内存占用”之间取得平衡。

4. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820133215337.png" alt="image-20250820133215337" style="zoom:80%;" /> 

   答：优点：函数返回时堆栈中申请的空间将被 **自动释放**，不会造成内存泄露。缺点：无法将要返回的数据存在函数内部申请的局部堆栈空间。

5. 题目：

   <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820133333001.png" alt="image-20250820133333001" style="zoom:80%;" /> 

   <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820133349941.png" alt="image-20250820133349941" style="zoom:80%;" /> 

   答：参考答案：

   <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\20201227152328.png" alt="2" style="zoom:80%;" /> 

6. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820133832047.png" alt="image-20250820133832047" style="zoom:80%;" /> 

   答：当然可以。动态内存分配来的空间在堆上，而不在栈上。堆上能申请到的空间要大很多很多，差不多 `1G`，在 `4G` 内存下。而栈上的简直少的可怜，貌似 `1M`？曾经有个面试题还考过能不能申请一个 `int[1024][1024]` 的局部数组？考察的就是函数栈空间很少造成申请失败。使用标量数据的动态分配只有在其被分配的值大于指针的大小时才有好处，显然对于 4 字节的整数，采用动态分配没有好处，因为必须有指针变量跟踪它所需要的空间和整数本身一样多。

7. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820133949203.png" alt="image-20250820133949203" style="zoom:80%;" /> 

   答：内存泄露。

------

## 编程

1. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820134025886.png" alt="image-20250820134025886" style="zoom:80%;" /> 

   ```
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   
   void *calloc(void *dst, size_t n, size_t size) {
       char *memory = (char *)malloc(n * size);
       if (memory != NULL) {
           char *ptr = memory;
           while (n --) {
               *ptr++ = '\0';
           }
       }
       return memory;
   }
   ```

2. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820134122443.png" alt="image-20250820134122443" style="zoom:80%;" /> 、

   答：见 `demo02.c`。

3. <img src="F:\Study_notes\Pointers_on_C\src\ch11\images\image-20250820135821674.png" alt="image-20250820135821674" style="zoom:80%;" /> 

   答：按字符读取字符串，写进缓冲区，动态判断读取字符的个数和缓冲区大小，若放不下则选择增容，`relloc()` 即可。最后由于记录了字符串个数，则直接 `malloc()` 申请一块刚好的内存将其放入进去即可。注意，`'\0'` 也要占一个空间！见 `demo03.c`。

















