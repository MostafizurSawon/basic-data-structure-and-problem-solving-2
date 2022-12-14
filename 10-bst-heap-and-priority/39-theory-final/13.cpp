void reversePrint(Node *head)
{
    Node *tail = NULL;
    while (head->next != NULL)
    {
        head = head->next;
    }
    tail = head;

    while (tail->prev != NULL)
    {
        cout<<tail->data;
        tail = tail->prev;
    }
    cout<< tail->data;
}

/*


    Doubly Linked List Merits:
        1) Double Linked is a linear linked list. we can store unlimited data.
        2) It used heap memory
        3) We don't have to say in advance how much data we want to store.
        4) We can traverse reverse order and non-reverse order in N time.
        5) We can insert and delete operations easily.
    Doubly Linked List Demerits :
        1) It search time complexity is high.
        2) It's GET operation time complexity is high 0(n).
        3) It does not data store linearly in memory
        4) It stores data randomly in memory
        5) It index access time complexity is not good.



*/
