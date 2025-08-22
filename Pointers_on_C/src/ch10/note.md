# 第十章 结构与联合

------

## 本章主要内容

<img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818134106430.png" alt="image-20250818134106430" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch10\images\20201227192116.png" alt="2" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch10\images\20201225145244.png" alt="3" style="zoom:80%;" /> 

------

## 笔记

结构体用的很广泛，它体现了一种数据的存储设计的方式，针对不同类型的数据采用不同的方式进行组织存储，这对于一个程序设计开发人员而言无疑是重要的。当然，里面也存在很多很多技巧，需要日后不断写代码加以巩固。当然，在 `C++` 中更是有 `class` 这个概念，模块化是非常重要的思想！

1. 结构：把不同类型的值储存在一起。

   直接访问：点操作符；间接访问：箭头操作符。

   **自引用：**

   <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818193741460.png" alt="image-20250818193741460" style="zoom:67%;" /> 

2. **什么时候你应该向函数传递一个结构而不是一个指向结构的指针呢？**

   很少有这种情况。只有当一个结构特别的小（长度和指针相同或更小）时，结构传递方案的效率才不会输给指针传递方案。但对于绝大多数结构，传递指针显然效率更高。如果你希望函数修改结构的任何成员，也应该使用指针传递方案。

3. 联合
   联合的所有成员引用的是内存的相同位置。

------

## 课后习题答案

1. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818194049165.png" alt="image-20250818194049165" style="zoom:80%;" /> 

   答：成员可以是不同类型，其按名称来访问，并非连续存储，有边界要求。而数组元素必须是同一类型，按下标访问，连续存储，边界对其元素。

2. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818194128365.png" alt="image-20250818194128365" style="zoom:80%;" /> 

   答：结构名为一个标量，作右值时，表示存储在结构中的值，作左值时，表示结构存储的内存位置。数组名为一个常量指针，其仅能作右值表示指向数组第一个元素的指针，不可以作左值。

3. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818194250972.png" alt="image-20250818194250972" style="zoom:80%;" /> 

   答：<img src="F:\Study_notes\Pointers_on_C\src\ch10\images\20201225150617.png" alt="4" style="zoom:80%;" /> 

4. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818194350754.png" alt="image-20250818194350754" style="zoom:80%;" /> 

   答：`abc` 是结构标记，而不是变量的名称。赋值语句非法。

5. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818194447086.png" alt="image-20250818194447086" style="zoom:80%;" /> 

   答：`abc` 是类型名，而不是变量名。赋值语句是非法的。

6. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818194622292.png" alt="image-20250818194622292" style="zoom:80%;" /> 

   答：`x = { 3, "hello" };`，`c` 的值可有可无，`x` 存储于静态内存中。

7. 题目：

   <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818194738363.png" alt="image-20250818194738363" style="zoom:80%;" /> 

   <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818194753960.png" alt="image-20250818194753960" style="zoom:80%;" /> 

   答：首先这个结构体大小为 12 字节。很不错的一道题啊！！！

   `nodes[3].c` 是**该结构体数组的起始地址**，是 200。

   `*nodes` 是`首元素`，即第一个结构。

   `np` 就是 `nodes` 的首地址加两个 `NODE`

   `npp` 是真滴秀...直接就是 216。200+4*4 = 216。

   <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\20201225151938.png" alt="5" style="zoom:80%;" /> 

8. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818195842315.png" alt="image-20250818195842315" style="zoom:80%;" /> 

   答：2个、6个。

9. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818202709415.png" alt="image-20250818202709415" style="zoom:80%;" /> 

   答：不确定字段是从右向左还是从左向右分配。字段与整形位数相关。如果字段太大，无法存储，不确定其是否会侵占下一个字段或者下一个字。

10. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818202738632.png" alt="image-20250818202738632" style="zoom:80%;" /> 

    答：<img src="F:\Study_notes\Pointers_on_C\src\ch10\images\20201225152523.png" alt="6" style="zoom:80%;" /> 

11. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818202833250.png" alt="image-20250818202833250" style="zoom:80%;" /> 

    答：保证字段不溢出是很不错的操作！

    <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\20201225152659.png" alt="7" style="zoom: 80%;" /> 

12. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818203148116.png" alt="image-20250818203148116" style="zoom:80%;" /> 

    答：2 或者 -2，取决于编译器。段只有 2 个二进制位，能表示的无符号范围是 0～3（如果看成有符号，则是 ‑2～1；这里未写 `unsigned`，但通常编译器把它当作 **unsigned** 位段，所以范围 0～3）。

13. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818203358695.png" alt="image-20250818203358695" style="zoom:80%;" /> 

    答：联合当做结构用，前两个值为垃圾，最后一个打印正确。

14. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818203539858.png" alt="image-20250818203539858" style="zoom:80%;" /> 

    答：用于存储数据的同一成员也必须用于读取数据。

15. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818203615010.png" alt="image-20250818203615010" style="zoom:80%;" /> 

    答：占空间。

------

## 编程

1. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818203641203.png" alt="image-20250818203641203" style="zoom:80%;" /> 

   答：<img src="F:\Study_notes\Pointers_on_C\src\ch10\images\20201225154054.png" alt="8" style="zoom:80%;" /> 

2. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818203744938.png" alt="image-20250818203744938" style="zoom:80%;" /> 

   答：

   ```
   /*
   ** Structure declaration for auto dealership sales records.
   */
   struct INFO1
   {
       char cust_name[21];
       char cust_addr[41];
       char model[21];
       enum
       {
           PURE_CASH,
           CASH_LOAN,
           LEASE
       } type;
       union
       {
           struct
           {
               float msrp;
               float sales_price;
               float sales_tax;
               float licensing_fee;
           } pure_cash;
           struct
           {
               float msrp;
               float sales_price;
               float sales_tax;
               float licensing_fee;
               float down_payment;
               int loan_duration;
               float interest_rate;
               f float monthly_payment;
               char bank[21];
           } cash_loan;
           struct
           {
               float msrp;
               float sales_price;
               float down_payment;
               float security_deposit;
               float monthly_payment;
               float lease_term;
           } lease;
       } info;
   };
   
   /*
   ** Improved structure declaration for auto dealership sales records.
   */
   struct INFO2
   {
       char cust_name[21];
       char cust_addr[41];
       char model[21];
       float msrp;
       float sales_price;
       enum
       {
           PURE_CASH,
           CASH_LOAN,
           LEASE
       } type;
       union
       {
           struct
           {
               float sales_tax;
               float licensing_fee;
           } pure_cash;
           struct
           {
               float sales_tax;
               float licensing_fee;
               float down_payment;
               int loan_duration;
               float interest_rate;
               float monthly_payment;
               char bank[21];
           } cash_loan;
           struct
           {
               float down_payment;
               float security_deposit;
               float monthly_payment;
               float lease_term;
           } lease;
       } info;
   };
   ```

3. <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818203832546.png" alt="image-20250818203832546" style="zoom:80%;" /> 

   <img src="F:\Study_notes\Pointers_on_C\src\ch10\images\image-20250818203849331.png" alt="image-20250818203849331" style="zoom:80%;" /> 

   答：

   ```
   /*
   ** Declaration of a structure to access the various parts of a machine
   ** instruction for a particular machine.
   */
   typedef union
   {
       unsigned short addr;
       struct
       {
           unsigned opcode : 10;
           unsigned dst_mode : 3;
           unsigned dst_reg : 3;
       } sgl_op;
       struct
       {
           unsigned opcode : 4;
           unsigned src_mode : 3;
           unsigned src_reg : 3;
           unsigned dst_mode : 3;
           unsigned dst_reg : 3;
       } dbl_op;
       struct
       {
           unsigned opcode : 7;
           unsigned src_reg : 3;
           unsigned dst_mode : 3;
           unsigned dst_reg : 3;
       } reg_src;
       struct
       {
           unsigned opcode : 8;
           unsigned offset : 8;
       } branch;
       struct
       {
           unsigned opcode : 16;
       } misc;
   } machine_inst;
   ```

   















































