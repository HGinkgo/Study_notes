# 第九章 字符串、字符和字节 

------

## 本章主要内容

<img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250814101300574.png" alt="image-20250814101300574" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250814101315605.png" alt="image-20250814101315605" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250814101340496.png" alt="image-20250814101340496" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250814101400224.png" alt="image-20250814101400224" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250814101419042.png" alt="image-20250814101419042" style="zoom:80%;" /> 

------

## 笔记

1. 标准库函数有时是用汇编语言实现的，目的就是为了充分利用某些机器所提供的特殊的字符串操纵指令，从而追求最大限度的速度。即使在没有这类特殊指令的机器上，你最好还是把更多的时间花在程序其他部分的算法改进上。寻找一种更好的算法比改良一种差劲的算法更有效率，复用已经存在的软件比重新开发一个效率更高。
2. 





------

## 课后习题答案

1. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816103954368.png" alt="image-20250816103954368" style="zoom:80%;" /> 

   1. 答：我个人感觉，是缺点。把各种事物混到一起或许效率能够大大提高，但出错几率也随之上升。就现代编程语言看来，**语法的孤立性** 是很重要的。即一件事情就对应一种解决方法就行了，搞太多方法容易混淆、出错。并且很显然，开发一个完整的字符串类型，并不影响传统的字符数组、字符串常量的使用。参考答案：

      AI一句话总结

      > C 语言把“字符串”退化成“一段以 0 结尾的内存”，牺牲了安全与便利，换来了极简与透明。
      > 对系统级任务，这是优点；对应用级任务，这是缺点。
      > 语言设计没有银弹，只有权衡。

2. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816104713589.png" alt="image-20250816104713589" style="zoom:80%;" /> 

   答：无符号更合适。从定义出发，长度怎么可能是负值呢？且无符号数表示正数范围比有符号大。但是无符号数的算术表达式可能会产生意外结果，而长度的优势在这体现的不明显。仁者见仁智者见智。

3. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816104806945.png" alt="image-20250816104806945" style="zoom:80%;" /> 

   答：后续的链式操作就能很方便的完成，不需要再次查找字符串结尾标志。

4. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816104851542.png" alt="image-20250816104851542" style="zoom:80%;" /> 

   答：`memcpy(y, x, 50);`

5. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816104933434.png" alt="image-20250816104933434" style="zoom:80%;" /> 

   答：不能。当且仅当数组中的最后一个字符已经为 `NUL` 才为有效字符串。`strncpy()` 不会为最后添加 `NUL`。

6. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816105243599.png" alt="image-20250816105243599" style="zoom:80%;" /> 

   答：可移植性更好。

7. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816105322873.png" alt="image-20250816105322873" style="zoom:80%;" /> 

   答：`toupper()` 函数会进行合法性判断。`islower()` 是不必要的。

8. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816105435098.png" alt="image-20250816105435098" style="zoom:80%;" /> 

   答：

------

## 编程

1. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816105626129.png" alt="image-20250816105626129" style="zoom:80%;" /> 

   答：见 `demo01.c`

2. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816110912284.png" alt="image-20250816110912284" style="zoom:80%;" /> 

   答：实现了个寂寞？如果在长度内找到了 `'\0'`，那么直接 `strlen()` 即可，如果没找到 `'\0'`，那么就返回该长度就行了。那么直接调用 `memchr()` 函数按字节查找 `'\0'` 是否出现不就行了？不过按循环来做，确实比较简洁！见 `demo02.c`。

3. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816111648936.png" alt="image-20250816111648936" style="zoom:80%;" /> 

   答：见 `demo03.c`。

4. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816111731846.png" alt="image-20250816111731846" style="zoom:80%;" /> 

   答：见 `demo04.c`。也需要传递数组的长度，并计算 `dst` 的长度，并且在 `dst` 中不要使用 `strlen()` 函数来确定其长度，因为不知道里面是否包含有效字符。故可以使用 `demo02.c` 中的 `my_strlen()` 函数，在已知数组大小的时候能返回正确的字符串长度。最后使用 `strncat()` 函数将字符串拼接过来，最终保证数组的最后一位元素是 `NUL`。在此按理说 `strncat()` 函数应该是要保证其末尾为 `NUL` 的。难道是在恰好拼接的情况下就不保证了吗?

5. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816130011024.png" alt="image-20250816130011024" style="zoom:80%;" /> 

   答：见 `demo05.c`。

6. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816132806951.png" alt="image-20250816132806951" style="zoom:80%;" /> 

   答：两种实现方式，`strlen()` 方法和 `register` 方法均可，其中后者不调用库函数，`register` 声明使得效率更高。见 `demo06.c`。

7. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816133250050.png" alt="image-20250816133250050" style="zoom:80%;" /> 

   答：见 `demo07.c`。

8. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816135106223.png" alt="image-20250816135106223" style="zoom:80%;" /> 

   答：`strchr()` 函数的应用，关键在于不能只写 `which --`，因为如果 `which < 0` 的话，怎么减也没有用，所以一开始要进行 `--which` 大于等于 0 的特判。让 `which` 前置 `--`，当 `which` 至少为 1 时，才有意义。见 `demo08.c`。

9. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816140150405.png" alt="image-20250816140150405" style="zoom:80%;" /> 

   答：`strpbrk()` 函数的应用。其找到第一次在 `str` 中出现的且在 `chars` 字符集合中的位置，并返回该位置的字符指针。循环处理即可，令 `str` 每次找到后往后移一位继续找就行了。见 `demo09.c`。

10. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816141939369.png" alt="image-20250816141939369" style="zoom:80%;" /> 

    答：见 `demo10.c`。把博主的循环改成 `while`

11. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816143259017.png" alt="image-20250816143259017" style="zoom:80%;" /> 

    答：见 `demo11.c`。`strtok()` 函数的应用。用其来找到以一个或多个空格结束的字符，`strtok()` 会将其末尾置为 `NUL`，循环来做，该函数会保存正在处理的字符串的局部信息，第一个参数传为 `NULL` 继续处理即可。

12. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816143858167.png" alt="image-20250816143858167" style="zoom:80%;" /> 

    答：见 `demo12.c`。

13. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816145739590.png" alt="image-20250816145739590" style="zoom:80%;" /> 

    答：见 `demo13.c`。

14. <img src="F:\Study_notes\Pointers_on_C\src\ch09\images\image-20250816152025666.png" alt="image-20250816152025666" style="zoom:80%;" /> 

    答：见 `demo14.c`。

    遍历得到 `*data`，运用 `strchr()` 函数找到在 `key` 中的出现位置，直接对 26 个字母进行下标映射即可。注意大小写字母的映射关系！利用 `<ctype.h>` 中的字符分类函数进行判断、转换。见 `demo14.c`。

    



