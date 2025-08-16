# 第二章 信息的表示与处理

## 主要内容

<img src="F:\Study_notes\CSAPP\src\ch03\images\image-20250811201713182.png" alt="image-20250811201713182" style="zoom:80%;" /> 

<img src="F:\Study_notes\CSAPP\src\ch03\images\image-20250811201801590.png" alt="image-20250811201801590" style="zoom:80%;" /> 

<img src="F:\Study_notes\CSAPP\src\ch03\images\image-20250811201818636.png" alt="image-20250811201818636" style="zoom:80%;" /> 

<img src="F:\Study_notes\CSAPP\src\ch03\images\image-20250811201834209.png" alt="image-20250811201834209" style="zoom:80%;" /> 

------

## 笔记

### 历史观点

一、为什么既要高级语言，又要看汇编

1. 开发效率与可移植性：
   高级语言抽象高、写代码快、跨平台编译即可运行。
   汇编/机器码与具体 ISA 强绑定，移植性差，但能看到“裸机”行为。
2. 读汇编的三大收益：
   洞悉编译器优化极限，定位隐藏的低效代码。
   还原高级语言隐藏的运行时细节（栈帧、寄存器分配、调用约定）。
   研究安全漏洞时，必须理解运行时控制流（栈溢出、ROP 等）。

二、机器级可见的核心状态

1. PC（Program Counter）：下一条指令的虚拟地址。
2. 寄存器组：极高速、具名的小容量存储（x86-64 有 %rax-%r15 等）。
3. 条件码（EFLAGS）：最近运算结果的 1-bit 标志（ZF/SF/CF/OF…），用于条件跳转。
4. 虚拟内存：程序看到的“大字节数组”；OS 负责映射到物理内存。

**对于机器级编程来说，有两个抽象十分重要：**

1. 由指令集体系结构或指令集架构（Instruction Set Architecture，ISA）来定义机器级程序的格式和行为，它定义了处理器状态、指令的格式，以及每条指令对状态的影响。大多数ISA都将程序的行为描述为按顺序执行每条指令。这是编译器的目标，提供一系列指令告诉机器要做什么。而微结构（Microarchitecture）是指这个架构的实现。
2. 机器级程序使用的内存地址是虚拟内存地址，使得内存模型看上去是一个很大的连续字节数组。然后由操作系统将其转换为真实的物理内存地址。在任意给定的时刻，只有有限的一部分虚拟地址是合法的。

我们这里的表述主要基于x86-64，它是Intel 64位体系结构，它的前身是32位的IA32。x86是对Intel处理器的口头称呼，因为第一个芯片被称为8086。x86又被称为复杂指令集计算机（Complex Instruction Set Computer，CISC）。目前处理器和常用的另一大类是ARM（Acorn RISC Machine），RISC是精简指令集计算机（Reduced Instruction Set Computer），由于它更简单，所以它比x86机器功耗更低。

### 程序编码

1. 





























------

## 课后习题

1. 

