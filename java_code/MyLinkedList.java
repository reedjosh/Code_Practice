class MyLinkedList{
    private Node head;
    private int listCount;
    
    // Constructor
    public MyLinkedList(){
        head = new Node(null);
        listCount=0;
        }

    public void add(Object data){
        Node temp = new Node(data);
        Node current = head;

        while (current.getNext() != null) {
            
