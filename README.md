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
 |---------|:---------------|:---|:----|:----|:----|:----
 |Vector/String| Back: O(1) or O(n) <br> Other: O(n)|O(1)|Back: O(1) <br> Other:O(n)| Sorted: O(log n) <br> Other: O(n) | No
