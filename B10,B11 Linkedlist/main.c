#include <stdio.h>
#include <stdlib.h>

typedef struct main
{
    /* data */
    int value;
    struct node* next;
}node;

node* createNode(int value){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

//void node_init(node* ptr){
//}

//thêm một node ở cuối
void push_back(node** array, int value){
    node *temp =temp = createNode(value); 
    
    if (*array == NULL){
        *array = temp;
    }
    else {
        node *p = *array;
        while (p ->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        
    }
}

// Lấy giá trị của một node 
int  get(node *array, int index){
    int i = 0 ;

    while (array->next != NULL && index != i)
    {
        array = array ->next;
        i++;
    }
    return array-> value;
}

//Thêm node ở một vị trí bất kì
void insert(node** array, int value, int pos){
    node* temp , * p;

    p = *array;
    temp = createNode(value);
    int i = 1 ;

    if (pos== 0){
        temp->next = *array;
        *array = temp;
    }else{

        while (p->next != NULL && pos != i)
        {
            p = p ->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

//Xóa node tại vị trí bất kỳ

void erase(node** array,  int pos){

    node* temp = *array;
    node* p = *array;
    int i = 0;

    if (pos == i){
        *array = temp->next;
        free(temp);
        temp = NULL;
    }
    else {
        while(temp != NULL && i != pos) {
            p = temp;
            temp = temp -> next;
            i++;
        }
        p->next = temp->next;
        free(temp);
    }

}

// kiểm tra xem Linked List có empty không
void list_empty(node *array){
    if (array == NULL){
        printf("Linked list is empty.\n");
    } else {
    printf("Linked list is not empty.\n");
    }
}

// Xóa node ở cuối list
void pop_back(node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* current = *head;
    node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous != NULL) {
        previous->next = NULL;
    } else {
        *head = NULL;
    }

    free(current);
}

// In Linked list
void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


int main(int argc , char const* argv[])
{
    node* array = NULL; // array có địa chỉ 0xc1
    //node_init(&array);
    push_back(&array, 7);

    push_back(&array, 4);

    push_back(&array,8);

    push_back (&array,16);
    push_back (&array,15);
    insert(&array,23,2);
    erase(&array, 2);

    pop_back(&array);
    pop_back(&array);

    printf("test: %d\n",get(array, 2));
    printList(array);

    list_empty(array);

    return 0;
}