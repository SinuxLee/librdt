# librdt
Redis Data Structure contains:  
-   sds: A simple dynamic string
-   adlist: A generic doubly linked list
-   ziplist: A specially encoded dually linked list
-   quicklist: A doubly linked list of ziplist
-   skiplist: 待整理
-   dict: Hash table
-   zipmap: A string map data structure optimized for size
-   intset: Integer set
-   rax: A radix tree

#### 工具类
siphash 一种哈希函数的实现方式  
endianconv 字节序由小端转到大端  
lzf 一种压缩算法  
