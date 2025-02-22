/*
    Here i added some Medium level Questions and their solutions on Linked List.
    By practicing these without any help will help you to understand the concept of Linked List.
    **Hint** Enter Alt + Z to wrap the code in Visual Studio Code.
    */

/*      Conceptual Questions:
1. Q: What is the difference between arrays and linked lists in terms of memory allocation?
   A: Arrays use contiguous memory locations, while linked lists use scattered memory locations
      connected through pointers. Arrays need continuous memory blocks, while linked lists can
      utilize fragmented memory spaces effectively.

2. Q: Why is insertion at the beginning O(1) in linked lists but O(n) in arrays?
   A: In linked lists, we only need to update the head pointer and one next pointer, regardless
      of list size. In arrays, we need to shift all elements right by one position to make space
      at the beginning.

3. Q: What is a self-referential structure? How is it used in linked lists?
   A: A self-referential structure is one that contains a pointer to a structure of the same type.
      In linked lists, each node is a self-referential structure as it contains a pointer to the
      next node of the same structure type.

4. Q: What are the advantages and disadvantages of using a tail pointer in a linked list?
   A: Advantages: O(1) insertion at end, quick access to last node
      Disadvantages: Extra memory for pointer, need to maintain tail pointer during deletions

5. Q: Why do we need to check if (head == NULL) in linked list operations?
   A: This check prevents segmentation faults by ensuring we don't try to access or modify
      elements in an empty list. It's a crucial edge case for maintaining program stability.

6. Q: What happens if we don't free deleted nodes in a linked list?
   A: Memory leaks occur - the memory remains allocated but becomes inaccessible. This can
      lead to program crashes if the application runs for a long time and memory gets exhausted.

7. Q: What is the difference between shallow copy and deep copy in linked lists?
   A: Shallow copy creates a new pointer pointing to the same list. Deep copy creates a
      completely new list with copied values. Changes in shallow copy affect original list.

8. Q: Why is random access O(n) in linked lists but O(1) in arrays?
   A: Linked lists require traversal from head to reach any position as elements aren't
      stored contiguously. Arrays can directly access any index using base address + offset.

9. Q: What is a dangling pointer in linked lists? Why is it dangerous?
   A: A dangling pointer points to a memory location that has been freed. It's dangerous
      because accessing or modifying this memory can cause undefined behavior or crashes.

10. Q: How does cache performance differ between arrays and linked lists?
    A: Arrays have better cache performance due to spatial locality (consecutive memory).
       Linked lists have poor cache performance as nodes can be scattered in memory.
*/

// Assuming we have a Node class defined as:
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// 1. Write a function to find the middle node of a linked list in one pass.
Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 2. Write a function to detect if a linked list has a cycle.
bool hasCycle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// 3. Write a function to reverse a linked list iteratively.
Node *reverse(Node *head)
{
    Node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 4. Write a function to remove duplicates from a sorted linked list.
void removeDuplicates(Node *head)
{
    Node *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
}

// 5. Write a function to find the nth node from the end of a linked list.
Node *nthFromEnd(Node *head, int n)
{
    Node *main_ptr = head, *ref_ptr = head;
    for (int i = 0; i < n && ref_ptr != nullptr; i++)
        ref_ptr = ref_ptr->next;

    if (ref_ptr == nullptr)
        return nullptr;

    while (ref_ptr != nullptr)
    {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    return main_ptr;
}

// 6. Write a function to check if a linked list is palindrome.
bool isPalindrome(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *second_half = reverse(slow->next);

    Node *first_half = head;
    while (second_half != nullptr)
    {
        if (first_half->data != second_half->data)
            return false;
        first_half = first_half->next;
        second_half = second_half->next;
    }
    return true;
}

// 7. Write a function to merge k sorted linked lists. This is a complex problem requiring use of min heap or divide and conquer.
Node *mergeKLists(vector<Node *> &lists)
{
    if (lists.empty())
        return nullptr;

    auto mergeTwoLists = [](Node *l1, Node *l2) -> Node *
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        Node *result;
        if (l1->data <= l2->data)
        {
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }
        return result;
    };

    int k = lists.size();
    while (k > 1)
    {
        for (int i = 0; i < k / 2; i++)
        {
            lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
        }
        k = (k + 1) / 2;
    }
    return lists[0];
}

// 8. Q: Write a function to rearrange a linked list in-place such that all even positioned nodes are after odd positioned nodes.
// Example: 1->2->3->4->5 becomes 1->3->5->2->4
Node *oddEvenList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *odd = head, *even = head->next, *evenStart = even;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    return head;
}
