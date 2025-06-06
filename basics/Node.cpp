class Node
  {
  private:
  int value;
  
  public:
  Node *next = __null;
  
  //constructor
  Node(int aValue){
    value = aValue;
    next = __null;
  }
  Node(){
    value = 0;
    next = __null;
  }
  //functions for value
  void set_value(int aValue){
    value = aValue;
  }
  int get_value(){
    return value;
  }
  
  //add node function
  void add_node(Node *aNext){
    next = aNext;
  }
};
