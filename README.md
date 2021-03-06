# Cplusplus-concepts

## Sample examples for c++ features

### Standard Template Library

|**Associative containers**||
|------|:-----------------
|set   | the value itself acts as a key  + ordered + key is unique + elements cannot be modified
|multiset| ordered + multiple elements of same value allowed
|map| key value pair + ordered + key is unique
|multimap| key value pair + ordered + key can hold multiple values
|Unordered_set|
|Unordered_multiset|
|unordered_map|
|Unordered_multimap|



| **Sequence containers**||
|---------|:---------------
|array | non-reaizable array
|vector| Dynamic array + faster random access
|list| double linked list
|dequeue| Double ended queue + faster random access
|forward_list| singly linked list|
|priority queues| keeps its elements ordered naturally



### **Iterators**
 ![](iterators.jpg)


 
 ### **Big(O) for various containers **

 ![](graph.png)

 | **Container**|**Insertion**|**Access**|**Erase**|**Find**|**Persistant Iterators**
 |----------------------|:----------------------|:----------------------|:----------------------|:----------------------|:----------------------
 |Vector/String| Back: O(1) or O(n) <br> Other: O(n)|O(1)|Back: O(1) <br> Other:O(n)| Sorted: O(log n) <br> Other: O(n) | No
 |deque| Back/Front: O(1) <br> Other: O(n)|O(1)|Back/Front: O(1) <br> Other: O(n)|Sorted: O(log n) <br> Other: O(n) | Pointers only
 | list/ forward_list| Back/Front: O(1) <br> With iterator: O(1) <br> Index: O(n)|Back/Front: O(1) <br> With iterator: O(1) <br> Index: O(n)| Back/Front: O(1) <br> With iterator: O(1) <br> Index: O(n)| O(n) | Yes
 |set / map| O(log n)|-| O(log n)|O(log n)|Yes
 |unordered_set / unordered_map|O(1) or O(n)|O(1) or O(n)|O(1) or O(n)|O(1) or O(n)| Pointers only
 |priority_queue|O(log n)|O(1)|O(log n)|-|-