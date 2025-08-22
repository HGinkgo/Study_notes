# 第十二章 使用结构与指针 

------

## 本章主要内容

<img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822155031402.png" alt="image-20250822155031402" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822155646091.png" alt="image-20250822155646091" style="zoom:80%;" /> 

<img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822155700427.png" alt="image-20250822155700427" style="zoom:80%;" /> 

------

## 笔记

没啥好说的，链表边界情况很多。现在要么在力扣上拿结构体写，要么数组模拟单链表，不过结构体每次 `malloc()` 是很耗时间的。每次只申请一个 `Node` 节点，貌似听哪位佬说过，申请一个大空间和申请一个小空间操作系统所用的时间相差不大，即申请次数越多，所耗时间越多。

链表也是基础了，双链表用的少。后续有邻接表在图论题目中经常用到！

本章可以理解为语法的应用，尤其是结构和指针的联合使用创造出了很厉害的数据结构，这些前面都已经接触过了，所以我动手写的很少，**初学者也不建议在这写，可以简单的写一写，然后数据结构直接找本书专项练习，大量写代码。**

------

## 课后习题答案

1. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822160539853.png" alt="image-20250822160539853" style="zoom:80%;" /> 

   答：当然可以。把有 `current` 的地方全部换成 `*list`，就行了。虽然少用了一个变量，但是增加了思维难度，不好理解，没啥大用途。

2. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822160647437.png" alt="image-20250822160647437" style="zoom:80%;" /> 

   答：我觉得很好用啊，`dummy->next = head;` 这样不知道简化了多少代码和思维量。然而书中确实给出了最优的解法，但是 `root` 节点不就是 `dummy` 节点吗？真的不清楚纠结这两者区别有啥用。虽说记录变化的 `link` 指针的思想确实很重要。见参考答案：

   <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\20201227162639.png" alt="2" style="zoom:80%;" /> 

3. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822160946430.png" alt="image-20250822160946430" style="zoom:80%;" /> 

   答：不改，在相同值的前面。改了，在最后面。

4. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822161102966.png" alt="image-20250822161102966" style="zoom:80%;" /> 

   答：我还以为要赋值为一个无效值...还是太年轻了啊...局部初始化、分离化设计、结构标签的不完整声明...tql！！！见参考答案：

   **看完了是真的牛逼！！！**

   <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\20201227163032.png" alt="2" style="zoom:80%;" /> 

5. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822161908821.png" alt="image-20250822161908821" style="zoom:80%;" /> 

   答：这是直接申请一个空间，且没有 `free()`。当每次有重复值的时候，就会内存泄露一个空间！

6. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822162216031.png" alt="image-20250822162216031" style="zoom:80%;" /> 

   答：当然可以，扫一遍找到一个最大、最小值，插入一个新有序链表即可。

7. 题目：

   <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822162320517.png" alt="image-20250822162320517" style="zoom:80%;" /> 

   <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822162341870.png" alt="image-20250822162341870" style="zoom:80%;" /> 

   答：<img src="F:\Study_notes\Pointers_on_C\src\ch12\images\20201227164028.png" alt="3" style="zoom:80%;" /> 

------

## 编程

1. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822163629283.png" alt="image-20250822163629283" style="zoom:80%;" /> 

   答：

   ```
   #include <stdio.h>
   
   typedef struct ListNode {
       int val;
       struct ListNode *next;
   } Node;
   
   int count(Node *node) {
       int cnt = 0;
       for (cnt; node; node = node->next) {
           cnt++;
       }
       return cnt;
   }
   ```

2. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822163748916.png" alt="image-20250822163748916" style="zoom:80%;" /> 

   答：没必要写这题。无序链表全部扫描完毕，有序链表如果扫描位置大于当前数，则不需要再扫描后面的了，直接返回即可。

3. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822163855267.png" alt="image-20250822163855267" style="zoom:80%;" /> 

   答：这使得函数更加复杂，主要是因为根指针不再是操作方法与节点指针相同。

   ```
   #if 0
   
   /*
   ** Remove a specified node from a doubly linked list. The first argument points
   ** to the root node for the list, and the second points to the node to be
   ** removed. TRUE is returned if it can be removed, otherwise FALSE is returned.
   */
   #include "doubly_linked_list_node.h"
   #include <assert.h>
   #include <stdio.h>
   #include <stdlib.h>
   #define FALSE 0
   #define TRUE 1
   int dll_remove(struct NODE *rootp, struct NODE *delete)
   {
       register Node *this;
       assert(delete != NULL);
       /*
   ** Find the node in the list and return FALSE if it is not there.
   ** Otherwise, delete it and return TRUE.
   */
       for (this = rootp–> fwd; this != NULL; this = this–> fwd)
           if (this == delete)
               break;
       if (this == delete)
       {
           /*
   ** Update fwd pointer of the previous node.
   */
           if (this–> bwd == NULL)
               rootp–> fwd = this–> fwd;
           else
               this–> bwd–> fwd = this–> fwd;
           /*
   ** Update bwd pointer of the next node.
   */
           if (this–> fwd == NULL)
               rootp–> bwd = this–> bwd;
           else
               this–> fwd–> bwd = this–> bwd;
           free(this);
           return TRUE;
       }
       else
           return FALSE;
   }
   
   #endif
   ```

4. 题目：

   <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822164037476.png" alt="image-20250822164037476" style="zoom:80%;" /> 

   <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822164053473.png" alt="image-20250822164053473" style="zoom:80%;" /> 

   答：反转链表的题目，leetcode刷过。

5. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822164202397.png" alt="image-20250822164202397" style="zoom:80%;" /> 

   答：

   <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\20201227165405.png" alt="4" style="zoom:80%;" /> 

   <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\20201227165533.png" alt="5" style="zoom:80%;" /> 

6. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822165259292.png" alt="image-20250822165259292" style="zoom:80%;" /> 

   答：参考答案：注意这个程序中的间接链:`this->bwd->fwd` 和 `this->fwd->bwd`: `if` 这两种表达方式都已经用过不止一次了，创造可能会更好保存值的临时变量。

7. <img src="F:\Study_notes\Pointers_on_C\src\ch12\images\image-20250822171059633.png" alt="image-20250822171059633" style="zoom:80%;" /> 

   答：两个列表中的节点在结构上不同，这一事实排除了使用单个插入函数的可能性对于列表；这很不幸，因为每种情况都需要相同的逻辑的声明如果任何其他源文件需要下面的解决方案，那么它们应该在包含文件中。

   ```
   #if 0
   
   /*
   ** Insert a word into a concordance list. The arguments are a pointer to the
   ** location that points to the first node in the list, and a string containing
   ** the word to be inserted. The function returns TRUE if the string begins with
   ** a letter and was inserted into the list, else FALSE.
   */
   #include <ctype.h>
   #include <malloc.h>
   #include <stdio.h>
   #include <string.h>
   #define TRUE 1
   #define FALSE 0
   /*
   ** Declaration for the secondary node that holds an individual word.
   */
   typedef struct WORD
   {
       char *word;
       struct WORD *next;
   } Word;
   /*
   ** Declaration for the primary node that heads a list of words.
   */
   typedef struct LIST
   {
       char letter;
       struct LIST *next;
       Word *word_list;
   } List;
   int concordance_insert(List **listp, char *the_word)
   {
       int first_char;
       List *current_list;
       Word *current_word;
       Word **wordp;
       int comparison;
       Word *new_word;
       /*
   ** Get the first character of the word and make sure it is valid.
   */
       first_char = *the_word;
       if (!islower(first_char))
           return FALSE;
       /*
   ** First, find the word list that begins with the right letter. If it
   ** does not exist, create a new one and add it.
   */
       while ((current_list = *listp) != NULL && current_list–> letter < first_char)
           listp = &current_list–> next;
       /*
   ** If current_list is NULL or points to a node with a letter larger
   ** than what we want, we’ve got to create a new word list and insert it
   ** here in the primary list.
   */
       if (current_list == NULL || current_list–> letter > first_char)
       {
           List *new_list;
           new_list = (List *)malloc(sizeof(List));
           if (new_list == NULL)
               return FALSE;
           new_list–> letter = first_char;
           new_list–> word_list = NULL;
           new_list–> next = current_list;
           *listp = new_list;
           current_list = new_list;
       }
   
       /*
   ** current_list now points to the node that heads the proper word list.
   ** Search down through it looking for our word.
   */
       wordp = &current_list–> word_list;
       while ((current_word = *wordp) != NULL)
       {
           comparison = strcmp(current_word–> word, the_word);
           if (comparison >= 0)
               break;
           wordp = &current_word–> next;
       }
       /*
   ** If current_word not NULL and comparison is 0, the word already is in
   ** the list.
   */
       if (current_word != NULL && comparison == 0)
           return FALSE;
       /*
   ** Create a new node for the word.
   */
       new_word = (Word *)malloc(sizeof(Word));
       if (new_word == NULL)
           return FALSE;
       new_word–> word = malloc(strlen(the_word) + 1);
       if (new_word–> word == NULL)
           return;
       strcpy(new_word–> word, the_word);
       /*
   ** Link the new node into the list.
   */
       new_word–> next = current_word;
       *wordp = new_word;
       return TRUE;
   }
   
   #endif 
   ```

   











