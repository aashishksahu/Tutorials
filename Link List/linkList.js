/**
 * Doubly linked list in JavaScript
 */

// node class defines the structure of a single node
// in a doubly link list
class node{
    constructor(payload, prevNode, nextNode){
        // prev points to the previous node
        this.prev = prevNode;
        // val holds the value to be stored
        this.val= payload;
        // next holds the next node
        this.next=nextNode;
    }
}

// head is the traveller reference
// it starts at null and travels forward 
// as each new node is created
var head = null;

// tail is right behind head, it's job is to
// help in assigning the previous node to the 
// current node
var tail = null;

// this marks the beginning of a linked list
var origin = null;


// function to create a linked list
function createNode(value){
    // create a node
    var newNode = new node(value, null, null);

    // if head is null, i.e., list is empty
    // then assign a new node to it
    // also mark the origin of the list
    if(head==null){
        head = newNode;
        origin = newNode;
        return head;
    }

    // if the list is not empty assign the newly created node
    // to the next reference of head
    // therefore, head now points to the next node
    head.next = newNode;
    // copy the reference of head in tail
    tail = head;
    // then move head one step ahead
    head = head.next;
    // now assign the previous node to the current node's prev reference
    head.prev = tail;

    // if successful return code 1
    return 1;
}


// function to print linklist
function printList(list){
    // if reached end of list, return 
    if(list == undefined){
        return list;
    }
    // print the current value
    console.log(list.val);
    // recursively traverse forward in the list by moving the reference
    // one step ahead unless reached the end of the list
    return printList(list.next);

}



for(let i = 0; i<10;i++){
    createNode(i*i);
}

// call this function to print the list
printList(origin);