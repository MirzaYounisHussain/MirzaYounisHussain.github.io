//1. Implement a List using Array and develop functions to perform insertion, deletion and linear search operations.
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int list[MAX];
int n = 0;
void insertInBeg(int value){
    if(n == MAX){
        printf("List is full !!!!\n");
        return;
    }
    for(int i = n-1; i>=0; i--){
        list[i+1] = list[i];
    }
    list[0] = value;
    n++;
    printf("Element Inserted !!!\n");
}
void insertAtEnd(int value){
    if(n == MAX){
        printf("List is full !!!!\n");
        return;
    }
    list[n++] = value;
    printf("Element Inserted !!!!\n");
}
void insertAtPosition(int pos, int value){
    if(n == MAX)
        printf("List is full !!!!\n");
    else if(pos < 0 || pos >= n)
        printf("Position is invalid !!!\n");
    else{
        for(int i= n-1; i>=pos; i--){
            list[i+1] = list[i];
        }
        list[pos] = value;
        n++;
        printf("Element Inserted !!!\n");
    }
}
void deleteFromBeg(){
    if(n == 0){
        printf("list is empty !!!\n");
        return;
    }
    for(int i=0; i<n-1; i++){
        list[i] = list[i+1];
    }
    n--;
    printf("Element deleted !!!!\n");
}
void deleteFromEnd(){
    if(n == 0){
        printf("list is empty !!!\n");
        return;
    }
    n--;
    printf("Element Deleted !!!!\n");
}
void deleteFromPosition(int pos){
    if(n == 0)
        printf("List is empty !!!\n");
    else if(pos < 0 || pos >= n)
        printf("Position is invalid !!!\n");
    else{
        for(int i=pos; i<n-1; i++){
            list[i] = list[i+1];
        }
        n--;
        printf("Element Deleted !!!!\n");
    }
}
void displayList(){
    if(n == 0){
        printf("List is empty !!!\n");
        return;
    }
    for(int i=0; i<n; i++){
        printf("%d\t", list[i]);
    }
    printf("\n");
}
int search(int value){
    for(int i=0; i<n; i++){
        if(list[i] == value)
            return i;
    }
    return -1;
}
int main(){
    while(1){
        printf("1. Insert In Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Any Position\n");
        printf("4. Delete From Beginning\n");
        printf("5. Delete From End\n");
        printf("6. Delete From Given Position\n");
        printf("7. Display List\n");
        printf("8. Search Element In List\n");
        printf("9. Exit\n");
        int choice, data, pos;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Data: ");
                scanf("%d", &data);
                insertInBeg(data);
                break;
            case 2:
                printf("Enter Data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter Position: ");
                scanf("%d", &pos);
                printf("Enter Data: ");
                scanf("%d", &data);
                insertAtPosition(pos, data);
                break;
            case 4:
                deleteFromBeg();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Enter Value To Search: ");
                scanf("%d", &data);
                int index = search(data);
                if(index != -1)
                    printf("Element Found At Index %d\n", index);
                else
                    printf("Element Not Found!!!\n");
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid Choice !!!!\n");
        }
        printf("\n");
    }
    return 0;
}




//2. Implement a Stack using Array and develop functions to perform push and pop operations.
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX], top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX-1;
}

void push(int value){
    if(isFull())
        printf("\nStack overflow. Cannot push into a stack. !!!\n");
    else{
        stack[++top] = value;
        printf("\nPushed %d into the stack. !!\n", value);
    }
}

int pop(){
    if(isEmpty()){
        printf("\nStack underflow. Cannot pop from empty stack. !!!\n");
        return -1;
    }
    else{
        int val = stack[top];
        top--;
        return val;
    }
}

int peek(){
    if(isEmpty()){
        printf("\nStack underflow. Cannot peek from empty stack. !!!\n");
        return -1;
    }
    else
        return stack[top];
}

void show(){
    if(isEmpty())
        printf("\nStack is empty !!!\n");
    else{
        printf("Stack elements are: \n");
        for(int i=top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
}
int main(){
    int choice, val, res;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                res = pop();
                if(res != -1)
                    printf("\n%d pop from stack. \n", res);
                break;
            case 3:
                res = peek();
                if(res != -1)
                    printf("\n%d is available at top of stack. \n", res);
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice...\n");
        }
        printf("\n");
    }
    return 0;
}



//3. Write a program to check if a given expression is correctly parenthesized using Stacks.
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter Expression: ");
    gets(str);
    int len = strlen(str), top = -1, flag = 0;
    char stack[len];
    for(int i=0; i<len; i++){
        char ch =  str[i];
        if(ch=='(' || ch=='[' || ch=='{')
            stack[++top] = ch;
        else if(ch==')' || ch==']' || ch=='}'){
            if(ch==')' && stack[top]=='(')
                top--;
            else if(ch==']' && stack[top]=='[')
                top--;
            else if(ch=='}' && stack[top]=='{')
                top--;
            else{
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0 && top == -1)
        printf("Balanced !!!");
    else
        printf("Not Balanced!!!!");
    return 0;
}



//4. Write a program to evaluate postfix, prefix and infix expressions using Stacks.
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int operand[100];
char operator[100];
int top1 = -1, top2 = -1;


void doProcess(){
    int x = operand[top1--];
    int y = operand[top1--];
    char op = operator[top2--];
    int z;
    switch(op){
        case '+':
            z = y + x;
            break;
        case '-':
            z = y - x;
            break;
        case '*':
            z = y * x;
            break;
        case '/':
            z = y / x;
            break;
        case '^':
            z = (int)round(pow(y, x));
            break;
    }
    operand[++top1] = z;
}


int precedence(char op){
    switch(op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


int evalInfixExpression(char* exp){
    for(int i=0; i<strlen(exp); i++){
        char ch = exp[i];
        if(isdigit(ch)){
            int num = 0;
            while(isdigit(exp[i])){
                num = num * 10 + exp[i]-'0';
                i++;
            }
            i--;
            operand[++top1] = num;
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            if(top2 == -1)
                operator[++top2] = ch;
            else{
                while(top2 != -1 && precedence(ch) < precedence(operator[top2])){
                        doProcess();
                }
                operator[++top2] = ch;
            }
        }
        else if(ch=='('){
            operator[++top2] = ch;
        }
        else if(ch==')'){
            while(operator[top2] != '('){
                doProcess();
            }
            top2--;
        }
    }
    while(top2 != -1){
        doProcess();
    }
    return operand[top1--];
}
int evalPostfixExpression(char* exp){
    for(int i=0; i<strlen(exp); i++){
        if(isdigit(exp[i])){
            int num = 0;
            while(isdigit(exp[i])){
                num = num*10 + exp[i]-'0';
                i++;
            }
            i--;
            operand[++top1] = num;
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'){
            int x = operand[top1--];
            int y = operand[top1--];
            int z;
            switch(exp[i]){
                case '+':
                    z = y + x;
                    break;
                case '-':
                    z = y - x;
                    break;
                case '*':
                    z = y * x;
                    break;
                case '/':
                    z = y / x;
                    break;
                case '^':
                    z = (int)round(pow(y, x));
                    break;
            }
            operand[++top1] = z;
        }
    }
    return operand[top1--];
}
int evalPrefixExpression(char* exp){
    for(int i=strlen(exp)-1; i>=0; i--){
        if(isdigit(exp[i])){
            int num = 0, p = 1;
            while(isdigit(exp[i])){
                num = num + (exp[i]-'0') * p;
                p = p * 10;
                i--;
            }
            i++;
            operand[++top1] = num;
        }
        else if(exp[i] == '+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'){
            int x = operand[top1--];
            int y = operand[top1--];
            int z;
            switch(exp[i]){
                case '+':
                    z = x + y;
                    break;
                case '-':
                    z = x - y;
                    break;
                case '*':
                    z = x * y;
                    break;
                case '/':
                    z = x / y;
                    break;
                case '^':
                    z = (int)round(pow(x, y));
                    break;
            }
            operand[++top1] = z;
        }
    }
    return operand[top1--];
}
int main(){
    char expr[100];
    printf("Enter Infix Expression: ");
    gets(expr);
    int result = evalInfixExpression(expr);
    printf("Result of expression %s = %d\n", expr, result);


    printf("Enter Postfix Expression: ");
    gets(expr);
    result = evalPostfixExpression(expr);
    printf("Result of expression %s = %d\n", expr, result);


    printf("Enter Prefix Expression: ");
    gets(expr);
    result = evalPrefixExpression(expr);
    printf("Result of expression %s = %d\n", expr, result);
    return 0;
}


//5. Write a program to convert an infix expression to its corresponding postfix and prefix expressions and vice-versa. 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int precedence(char opr){
    switch (opr){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
char* convertInfixToPostfix(char* infixExp){
    int len = strlen(infixExp), top = -1, x = 0;
    char* postfix = (char*) malloc(len+1);
    char operator[len];
    for(int i=0; i<len; i++){
        char ch = infixExp[i];
        if(isalnum(ch)){
            postfix[x++] = ch;
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            while(top!=-1 && precedence(ch)<=precedence(operator[top]) && ch!='^'){
                postfix[x++] = operator[top--];
            }
            operator[++top] = ch;
        }
        else if(ch=='('){
            operator[++top] = ch;
        }
        else if(ch==')'){
            while(operator[top] != '('){
                postfix[x++] = operator[top--];
            }
            top--;
        }
    }
    while(top != -1){
        postfix[x++] = operator[top--];
    }
    postfix[x] = '\0';
    return postfix;
}
char* convertInfixToPrefix(char* infixExp){
    int len = strlen(infixExp), top = -1, x = 0;
    char* prefix = (char*) malloc(len+1);
    char operator[len];
    for(int i=len-1; i>=0; i--){
        char ch = infixExp[i];
        if(isalnum(ch)){
            prefix[x++] = ch;
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            while(top!=-1 && (precedence(ch)<precedence(operator[top]) || (precedence(ch)==precedence(operator[top]) && ch=='^'))){
                prefix[x++] = operator[top--];
            }
            operator[++top] = ch;
        }
        else if(ch==')'){
            operator[++top] = ch;
        }
        else if(ch=='('){
            while(operator[top] != ')'){
                prefix[x++] = operator[top--];
            }
            top--;
        }
    }
    while(top != -1){
        prefix[x++] = operator[top--];
    }
    prefix[x] = '\0';
    strrev(prefix);
    return prefix;
}
char* convertPostfixToInfix(char *postfixExp){
    int len = strlen(postfixExp), top = -1;
    char stack[100][100];
    for(int i=0; i<len; i++){
        char ch = postfixExp[i];
        if(isalnum(ch)){
            char str[]={ch,'\0'};
            strcpy(stack[++top], str);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            char *s1 = stack[top--];
            char *s2 = stack[top--];
            char s3[100];
            sprintf(s3, "(%s%c%s)", s2, ch, s1);
            strcpy(stack[++top], s3);
        }
    }
    char *infix = (char*)malloc(strlen(stack[top])+1);
    strcpy(infix, stack[top--]);
    return infix;
}
char* convertPrefixToInfix(char *prefixExp){
    int len = strlen(prefixExp), top = -1;
    char stack[100][100];
    for(int i=len-1; i>=0; i--){
        char ch = prefixExp[i];
        if(isalnum(ch)){
            char str[]={ch,'\0'};
            strcpy(stack[++top], str);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            char *s1 = stack[top--];
            char *s2 = stack[top--];
            char s3[100];
            sprintf(s3, "(%s%c%s)", s1, ch, s2);
            strcpy(stack[++top], s3);
        }
    }
    char *infix = (char*)malloc(strlen(stack[top])+1);
    strcpy(infix, stack[top--]);
    return infix;
}
int main(){
    char expr[100];
    printf("Enter Infix Expression: ");
    gets(expr);
    printf("Postfix expression = %s\n", convertInfixToPostfix(expr));
    printf("Prefix expression = %s\n", convertInfixToPrefix(expr));
    printf("Enter Postfix Expression: ");
    gets(expr);
    printf("Infix expression = %s\n", convertPostfixToInfix(expr));
    printf("Enter Prefix Expression: ");
    gets(expr);
    printf("Infix expression = %s\n", convertPrefixToInfix(expr));
    return 0;
}



//6. Implement a Queue using Array and develop functions to perform enqueue and dequeue operations.
#include<stdio.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
int isEmpty(){
    return front == -1 || front > rear;
}
int isFull(){
    return rear == MAX-1;
}
void enqueue(int data){
    if(isFull()){
        printf("\nQueue Overflow!!!\n");
        return;
    }
    queue[++rear] = data;
    if(front == -1)
        front = rear;
    printf("\n%d inserted in queue\n", data);
}
int dequeue(){
    if(isEmpty()){
        printf("Queue Undeflow!!!\n");
        return -1;
    }
    int val = queue[front++];
    if(front>rear)
        front = rear = -1;
    return val;
}
int peek(){
    if(isEmpty()){
        printf("Queue Undeflow!!!\n");
        return -1;
    }
    return queue[front];
}
void display(){
    if(isEmpty()){
        printf("Queue is empty!!!\n");
        return;
    }
    for(int i = front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
}
int main(){
    int choice, value;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value != -1)
                    printf("%d dequeue from queue!!!\n", value);
                break;
            case 3:
                value = peek();
                if(value != -1)
                    printf("%d dequeue from queue!!!\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice !!!!\n");
        }
    }
    return 0;
}



//7. Implement a Singly Linked List and develop functions to perform insertion, deletion and linear search operations.
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insertNodeInBeg(int data){
    struct Node * newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head  = newNode;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtEnd(int data){
    struct Node * newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtAnyPos(int data, int pos){ // here position is 0-base
    if(head == NULL){
        printf("List is empty !!!\n");
    }
    else if(pos == 0){
        insertNodeInBeg(data);
    }
    else{
        struct Node* temp = head;
        int i = 0;
        while(temp != NULL){
            if(i == pos-1)
                break;
            temp = temp->next;
            i++;  
        }
        if(temp == NULL || temp->next==NULL){
            printf("Invalid position!!!\n");
        }
        else{
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node Inserted !!!\n");
        }
    }
}
void deleteNodeFromBeg(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else{
        head = head->next;
        printf("Node deleted !!!\n");
    }
}
void deleteNodeFromEnd(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else if(head->next == NULL){ // only single node
        head = NULL;
    }
    else{
        struct Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        printf("Node deleted !!!\n");
    }
}
void deleteNodeFromAnyPos(int pos){ // Here position is 0 base
    if(head == NULL)
        printf("List is empty !!!\n");
    else if(pos == 0)
        deleteNodeFromBeg();
    else{
        struct Node* temp =  head;
        int i = 0;
        while(temp != NULL){
            if(i == pos-1)
                break;
            temp = temp->next;
            i++;
        }
        if(temp == NULL || temp->next == NULL)
            printf("Invalid position !!!\n");
        else{
            temp->next = temp->next->next;
            printf("Node deleted !!!\n");
        }
    }
}
void search(int value){
    if(head == NULL)
        printf("List is empty !!!\n");
    else{
        struct Node* temp = head;
        while(temp != NULL){
            if(temp->data == value){
                printf("Found!!!\n");
                return;
            }
            temp = temp->next;
        }
        printf("Not Found !!!\n");
    }
}
void displayList(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else{
        struct Node* temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    while(1){
        printf("\n***** Singly Linked List *****\n");
        printf("1. Insert In Begining\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Specified Position\n");
        printf("4. Detele From Begining\n");
        printf("5. Delete From End\n");
        printf("6. Delete From Specified Position\n");
        printf("7. Display List\n");
        printf("8. Search Element In List\n");
        printf("9. Exit\n");
        int choice, data, pos;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Data: ");
                scanf("%d", &data);
                insertNodeInBeg(data);
                break;
            case 2:
                printf("Enter Data: ");
                scanf("%d", &data);
                insertNodeAtEnd(data);
                break;
            case 3:
                printf("Enter Position: ");
                scanf("%d", &pos);
                printf("Enter Data: ");
                scanf("%d", &data);
                insertNodeAtAnyPos(data, pos);
                break;
            case 4:
                deleteNodeFromBeg();
                break;
            case 5:
                deleteNodeFromEnd();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deleteNodeFromAnyPos(pos);
                break;
            case 7:
               displayList();
               break;
            case 8:
                printf("Enter Searching Element: ");
                scanf("%d", &data);
                search(data);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid Choice !!!!!\n");
        }
    }
    return 0;
}



//8. Implement a Doubly Linked List and develop functions to perform insertion, deletion and linear search operations.
#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* createnode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data= data;
    temp->prev=temp->next = NULL;  
    return temp;
};
void insertNodeInBeg(int data){
    struct Node* newnode = createnode(data);
    if(head==NULL && tail==NULL){                    
        head = tail = newnode;
    }
    else{
        newnode->next=head;      
        head->prev=newnode;
        head=newnode;          
    }
    printf("\nNode inserted....\n");
}
void insertNodeAtEnd(int data){
    struct Node* newnode = createnode(data);
    if(head==NULL && tail == NULL){
        head = tail = newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
     printf("\nNode inserted....\n");
}
void insertNodeAtAnyPos(int data, int pos){
    struct Node* newnode = createnode(data);
    if(head == NULL && pos == 0){
        struct Node* newnode = createnode(data);
        head=tail=newnode;                                              
        printf("\nNode inserted at position %d...\n",pos);
    }
    else if(pos == 0){
        struct Node* newnode = createnode(data);
        newnode->next = head;
        head = newnode;
        printf("\nNode inserted at position %d...\n",pos);
    }
    else{
        struct Node* temp = head;
        int i=0;
        while(temp != NULL){
            if(i==pos){
               break;
            }
            temp=temp->next;
            i++;
        }
        if(temp == NULL && i!= pos){                    
            printf("\n....Invalid Position....\n");    
        }
        else if(i==pos){
            insertNodeAtEnd(data);                              
            printf("\nNode inserted at position %d...\n",pos);
        }
        else{
            struct Node* newnode = createnode(data);
            temp->prev->next=newnode;
            newnode->prev=temp->prev;
            newnode->next=temp;
            temp->prev=newnode;
            printf("\nNode inserted at position %d...\n,pos");
        }
    }
}
void deleteNodeFromBeg(){
    if(head==NULL && tail == NULL){
        printf("\nList is empty....\n");
    }
    else if(head==tail){      
        head=tail=NULL;
        printf("\nNode deleted...\n");
    }
    else{            
        head = head-> next;
        printf("\nNode deleted...\n");
    }
}
void deleteNodeFromEnd(){
    if(head==NULL && tail == NULL){
        printf("\nList is empty....\n");
    }
    else if(head==tail){       //or we can use condition head->next=NULL
        struct Node* delnode = head;
        head=tail=NULL;
        free(delnode);
        printf("\nNode deleted...\n");
    }
    else{
        tail->prev->next = NULL;
        tail = tail-> prev;
        printf("\nNode deleted...\n");
    }
}
void deleteNodeFromAnyPos(int pos){
    if(head==NULL && tail==NULL)
      printf("\nlist is empty...\n");
    else if(pos==0)
        deleteNodeFromBeg();
    else{
        struct Node* temp = head;
        int i=0;
        while(temp != NULL && i!=pos){
            temp=temp->next;                          
            i++;
        }
        if(temp==NULL && i!=pos){
            printf("\nInvalid Position...\n");
        }
        else if(i==pos){                                      
            deleteNodeFromEnd();                              
            printf("\nNode deleted from position %d...\n",pos);
        }
        else{                                                  
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
}
void search(int val){
    if(head==NULL && tail ==NULL){
        printf("List is Empty.\n");
    }
    else{
         struct Node* temp = head;
        while(temp != NULL){
            if(temp->data == val){
                printf("Found.\n");
                return;
            }
            temp = temp->next;
        }
        printf("Not Found.\n");
    }
}
void display(){                      
     if(head==NULL && tail ==NULL){
        printf("List is Empty.\n");
    }
    else{
         struct Node* temp = head;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    while(1){
        printf("\n-_____Doubly Linked list _____-\n");
        printf("1. Insert In Beginning\n");
        printf("2. Insert In end\n");
        printf("3. Insert At Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from any position\n");
        printf("7. Display List\n");
        printf("8. Search element in list\n");
        printf("9. Exit\n");
        int choice, data, pos;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data : ");
                scanf("%d",&data);
                insertNodeInBeg(data);
                break;
            case 2:
                printf("Enter data : ");
                scanf("%d",&data);
                insertNodeAtEnd(data);
                break;
            case 3:
                printf("Enter position : ");
                scanf("%d",&pos);
                printf("Enter data : ");
                scanf("%d",&data);
                insertNodeAtAnyPos(data,pos);  
                break;
            case 4:
                deleteNodeFromBeg();
                break;
            case 5:
                deleteNodeFromEnd();
                break;
            case 6:
                printf("Enter position : ");
                scanf("%d",&pos);
                deleteNodeFromAnyPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter value to search : ");
                scanf("%d",&data);
                search(data);
                break;
            case 9:
                exit(0);
                break;
        }
    }
    return 0;
}



//9. Implement a Circular Linked List and develop functions to perform insertion, deletion and linear search operations.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}
void insertNodeInBeg(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtEnd(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node inserted !!!\n");
}
void insertNodeAtAnyPos(int data , int pos){
    if(head == NULL){
        if(pos==0)
            insertNodeInBeg(data);
        else
            printf("Invalid position !!!\n");
    }
    else if(pos == 0)
        insertNodeInBeg(data);
    else{
        struct Node* temp = head;
        int i = 0;
        while(i != pos-1 ){
            temp = temp->next;
            i++;
            if(temp == head){
                printf("Invalid position !!!\n");
                return;
            }
        }
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node Inserted !!!\n");
    }
}
void deleteNodeFromBeg(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else if(head->next == head){
        head = NULL;
        printf("Node deleted!!!\n");
    }
    else{
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        printf("Node deleted !!!\n");
    }
}
void deleteNodeFromEnd(){
    if(head == NULL)
        printf("List is empty !!!\n");
    else if(head->next == head){
        head = NULL;
        printf("Node deleted!!!\n");
    }
    else{
        struct Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        temp->next = head;
        printf("Node deleted !!!\n");
    }
}


void deleteNodeFromAnyPos(int pos){           // 0 based.
    if(head == NULL)
        printf("List is empty !!\n");
    else if(pos == 0)
        deleteNodeFromBeg();
    else{
        struct Node* temp = head;
        int i = 0;
        while(i != pos-1 && temp->next != head){
            i++;
            temp = temp->next;
        }
        if(temp->next == head)
            printf("Invalid position !!!\n");
        else{
            temp->next = temp->next->next;
            printf("Node deleted !!!\n");
        }
    }
}
void search(int val){
    if(head == NULL){
        printf("List is empty !!\n");
    }
    else{
        struct Node* temp = head;
        do{
            if(temp->data == val){
                printf("Found !!!\n");
                return;
            }
            temp = temp->next;
        }while(temp != head);
        printf("Not Found !!!\n");
    }
}
void display(){
    if(head == NULL){
        printf("List is empty !!\n");
    }
    else{
        struct Node* temp = head;
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("\n");
    }
}
int main(){
    while(1){
        printf("\n-_____Circular Singly Linked list _____-\n");
        printf("1. Insert In Beginning\n");
        printf("2. Insert In end\n");
        printf("3. Insert At Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from any position\n");
        printf("7. Display List\n");
        printf("8. Search element in list\n");
        printf("9. Exit\n");
        int choice, data, pos;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data : ");
               scanf("%d",&data);
               insertNodeInBeg(data);
               break;
            case 2:
               printf("Enter data : ");
               scanf("%d",&data);
               insertNodeAtEnd(data);
               break;
            case 3:
                printf("Enter position : ");
                scanf("%d", &pos);
                printf("Enter data : ");
                scanf("%d",&data);
                insertNodeAtAnyPos(data,pos);  
                break;
            case 4:
                deleteNodeFromBeg();
                break;
            case 5:
                deleteNodeFromEnd();
                break;
            case 6:
                printf("Enter Position : ");
                scanf("%d",&pos);
                deleteNodeFromAnyPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter value to search : ");
                scanf("%d",&data);
                search(data);
                break;
            case 9:
                exit(0);
                break;
        }
    }
    return 0;
}



//10. Implement a Stack using Linked List and develop functions to perform push and pop operations.
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        printf("Stack overflow!!!\n");
    else{
        temp->data = data;
        temp->next = NULL;
        temp->next = top;
        top = temp;
        printf("%d push into the stack!!!\n", data);
    }
}
int pop(){
    if(top == NULL){
        printf("Stack Underflow!!!\n");
        return -1;
    }
    else{
        int val = top->data;
        top = top->next;
        return val;
    }
}
int peek(){
    if(top == NULL){
        printf("Stack Underflow!!!\n");
        return -1;
    }
    else{
        return top->data;
    }
}
void show(){
    if(top == NULL)
        printf("Stack is empty !!!\n");
    else{
        struct Node* temp = top;
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    int data, choice, res;
    while(1){
        printf("\n***** Stack Menu *****\n");
        printf("1. Push\n");
        printf("2. pop\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                res = pop();
                if(res != -1)
                    printf("%d pop from the stack!!\n", res);
                break;
            case 3:
                res = peek();
                if(res != -1)
                    printf("Top element is %d!!\n", res);
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
            case 6:
                printf("Invalid Choice !!!\n");
        }
    }
    return 0;
}



//11. Implement a Queue using Linked List and develop functions to perform enqueue and dequeue operations.
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        printf("Queue overflow!!!\n");
    else{
        temp->data= data;
        temp->next = NULL;
        if(front == NULL && rear == NULL)
            front = rear = temp;
        else{
            rear->next = temp;
            rear = temp;
        }
        printf("%d push into the queue !!!\n", data);
    }
}
int dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue undeflow!!!\n");
        return -1;
    }
    else{
        int val = front->data;
        front = front->next;
        if(front == NULL)
            rear = front;
        return val;
    }
}
int peek(){
    if(front == NULL && rear == NULL){
        printf("Queue undeflow!!!\n");
        return -1;
    }
    else{
        return front->data;
    }
}
void show(){
    if(front == NULL && rear == NULL)
        printf("Queue is empty !!!\n");
    else{
        struct Node* temp = front;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    int data, choice, res;
    while(1){
        printf("\n***** Queue Menu *****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                res = dequeue();
                if(res != -1)
                    printf("%d pop from the queue!!\n", res);
                break;
            case 3:
                res = peek();
                if(res != -1)
                    printf("Front element of queue is %d!!\n", res);
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
            case 6:
                printf("Invalid Choice !!!\n");
        }
    }
    return 0;
}



//12. Implement a Priority Queue using Linked List and develop functions to perform enqueue and dequeue operations.
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    int priority;
    struct Node* next;
};
struct Node* front = NULL, *rear = NULL;
void enqueue(int data, int priority){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        printf("Queue overflow!!!\n");
    else{
        temp->data= data;
        temp->priority = priority;
        temp->next = NULL;
        if(front == NULL && rear == NULL)
            front = rear = temp;
        else{
            rear->next = temp;
            rear = temp;
        }
        printf("%d push into the queue !!!\n", data);
    }
}
struct Node* getHighestPriority(){
    struct Node *curr = front, *prev = NULL, *temp = NULL;
    int max = 0;
    while(curr != NULL){
        if(curr->priority > max){
            max = curr->priority;
            temp = prev;
        }
        prev= curr;
        curr = curr->next;
    }
    return temp;
}
int dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue undeflow !!!\n");
        return -1;
    }
    else if(front == rear){
        int val = front->data;
        front = rear = NULL;
        return val;
    }
    else{
        struct Node* temp = getHighestPriority();
        int val;
        if(temp == NULL){
            val = front->data;
            front = front->next;
        }
        else{
            val = temp->next->data;
            temp->next = temp->next->next;
        }
        return val;
    }
}
int peek(){
    if(front == NULL && rear == NULL){
        printf("Queue undeflow !!!\n");
        return -1;
    }
    else if(front == rear){
        return front->data;
    }
    else{
        struct Node* temp = getHighestPriority();
        int val;
        if(temp == NULL){
            val = front->data;
        }
        else{
            val = temp->next->data;
        }
        return val;
    }
}
void show(){
    if(front == NULL && rear == NULL)
        printf("Queue is empty !!!\n");
    else{
        struct Node* temp = front;
        while(temp != NULL){
            printf("priority : %d --> value : %d\n", temp->priority, temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    int data, choice, res, priority;
    while(1){
        printf("\n***** Priority Queue Menu *****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter Priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                res = dequeue();
                if(res != -1)
                    printf("%d pop from the queue!!\n", res);
                break;
            case 3:
                res = peek();
                if(res != -1)
                    printf("Front element of queue is %d!!\n", res);
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
            case 6:
                printf("Invalid Choice !!!\n");
        }
    }
    return 0;
}



//13. Implement a Binary Tree using Array and develop functions to perform traversal, searching, insertion and deletion operations.
#include<stdio.h>
#include<stdlib.h>
#define max 100
int tree[max], idx = 13;
void initTree(){
    for(int i=0; i<max; i++){
        tree[i] = -1;
    }
}
void insert(int val){   // Here we are inserting data in BT using level order
    if(idx == max)
        printf("Tree is full !!!\n");
    else{
        tree[idx++] = val;
    }
}
void levelOrder(){
    if(idx == 0)
        printf("Tree is empty!!!\n");
    else{
        for(int i=0; i<idx; i++){
            if(tree[i] != -1)
                printf("%d ", tree[i]);
        }
    }
}
void preOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    printf("%d ", tree[index]);
    preOrder(2*index+1);
    preOrder(2*index+2);
}
void inOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    inOrder(2*index+1);
    printf("%d ", tree[index]);
    inOrder(2*index+2);
}
void postOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    postOrder(2*index+1);
    postOrder(2*index+2);
    printf("%d ", tree[index]);
}
int main(){
    int choice, value;
    initTree();
    while(1){
        printf("\n***** Binary Tree Menu *****\n");
        printf("1. Insert\n");
        printf("2. Level Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. In-Order Traversal\n");
        printf("5. Post-Order Traversal\n");
        printf("6. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                levelOrder();
                break;
            case 3:
                preOrder(0);
                break;
            case 4:
                inOrder(0);
                break;
            case 5:
                postOrder(0);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice !!!\n");
        }
    }
    return 0;
}



//14. Implement a Binary Search Tree using Array and develop functions to perform traversal, searching, insertion and deletion operations.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* left;
    int data;
    struct Node* right;
} Node;
Node* createNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node* insert(Node* root, int data){
    if(root == NULL)
        return createNode(data);
    else{
        Node* queue[100];
        int front = -1, rear = -1;
        queue[++rear] = root;
        front++;
        while(front<=rear){
            Node* temp = queue[front++];
            if(temp->left == NULL){
                temp->left = createNode(data);
                break;
            }
            else if(temp->right == NULL){
                temp->right = createNode(data);
                break;
            }
            else{
                queue[++rear] = temp->left;
                queue[++rear] = temp->right;
            }
        }
        return root;
    }
}
Node* search(Node* root, int val){
    if(root== NULL)
        return NULL;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;
        front++;
    while(front<=rear){
        Node* temp = queue[front++];
        if(temp->data == val)
            return temp;
        if(temp->left != NULL)
            queue[++rear] = temp->left;
        if(temp->right != NULL)
            queue[++rear] = temp->right;
    }
    return NULL;
}
void delete(Node* root, int val){
    if(root== NULL)
        return NULL;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;
    front++;
    Node *t1=NULL, *t2=NULL, *temp=NULL;
    while(front<=rear){
        temp = queue[front++];
        if(temp->data == val)
            t1 = temp;
        if(temp->left != NULL)
            queue[++rear] = temp->left;
        if(temp->right != NULL)
            queue[++rear] = temp->right;
    }
    t2 = temp;
    if(t1 == NULL)
        printf("Element not found !!!\n");
    else{
        t1->data = t2->data;
        front = rear = -1;
        queue[++rear] = root;
        front++;
        while(front<=rear){
            Node* temp = queue[front++];
            if(temp->left == t2){
                temp->left = NULL;
                break;
            }
            if(temp->right == t2){
                temp->right = NULL;
                break;
            }
            if(temp->left != NULL)
                queue[++rear] = temp->left;
            if(temp->right != NULL)
                queue[++rear] = temp->right;
        }
        printf("Node deleted !!!\n");
    }
}
void preOrder(Node* root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
int main(){
    int choice, val;
    Node* root = NULL;
    while (1){
        printf("\n ***** Binary Tree Menu *****\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                preOrder(root);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                postOrder(root);
                break;
            case 5:
                printf("Enter Seaching Element: ");
                scanf("%d", &val);
                if(search(root, val) == NULL)
                    printf("Not Found !!\n");
                else
                    printf("Found!!!\n");
                break;
            case 6:
                printf("Enter Deleting Element: ");
                scanf("%d", &val);
                delete(root, val);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice !!!!\n");
        }
    }
   
}



//15. Implement a Binary Tree using Linked List and develop functions to perform traversal, searching, insertion and deletion operations.
#include<stdio.h>
#include<stdlib.h>
#define max 100
int tree[max];
void initTree(){
    for(int i=0; i<max; i++){
        tree[i] = -1;
    }
}
void insert(int index, int val){
    if(tree[index]==-1)
        tree[index] = val;
    else if(val < tree[index])
        insert(2*index+1, val);
    else
        insert(2*index+2, val);
}
int search(int index, int val){
    if(index >= max || tree[index] == -1)
        return -1;
    else if(val == tree[index])
        return index;
    else if(val < tree[index])
        return search(2*index+1, val);
    else
        return search(2*index+2, val);
}
void preOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    printf("%d ", tree[index]);
    preOrder(2*index+1);
    preOrder(2*index+2);
}
void inOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    inOrder(2*index+1);
    printf("%d ", tree[index]);
    inOrder(2*index+2);
}
void postOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    postOrder(2*index+1);
    postOrder(2*index+2);
    printf("%d ", tree[index]);
}
int main(){
    int choice, val;
    initTree();
    while (1){
        printf("\n ***** Binary Search Tree Menu *****\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &val);
                insert(0, val);
                break;
            case 2:
                preOrder(0);
                break;
            case 3:
                inOrder(0);
                break;
            case 4:
                postOrder(0);
                break;
            case 5:
                printf("Enter Seaching Element: ");
                scanf("%d", &val);
                if(search(0, val) == -1)
                    printf("Not Found !!\n");
                else
                    printf("Found!!!\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice !!!!\n");
        }
    }
   
}




//16. Implement a Binary Search Tree using Linked List and develop functions to perform traversal, searching, insertion and deletion operations.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* left;
    int data;
    struct Node* right;
} Node;
Node* createNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node* insert(Node* root, int data){
    if(root == NULL)
        return createNode(data);
    else if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
Node* search(Node* root, int val){
    if(root == NULL)
        return NULL;
    else if(root->data == val)
        return root;
    else if(val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}
Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* delete(Node* root, int val){
    if(root == NULL)
        return NULL;
    else if(val < root->data)
        root->left = delete(root->left, val);
    else if(val > root->data)
        root->right = delete(root->right, val);
    else{
        //Having zero-child
        if(root->left == NULL && root->right == NULL)
            return NULL;
        //Having one-child
        else if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        //having two child
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
        return root;
    }
}
void preOrder(Node* root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
int main(){
    int choice, val;
    Node* root = NULL;
    while (1){
        printf("\n ***** Binary Search Tree Menu *****\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                preOrder(root);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                postOrder(root);
                break;
            case 5:
                printf("Enter Seaching Element: ");
                scanf("%d", &val);
                if(search(root, val) == NULL)
                    printf("Not Found !!\n");
                else
                    printf("Found!!!\n");
                break;
            case 6:
                printf("Enter Deleting Element: ");
                scanf("%d", &val);
                delete(root, val);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice !!!!\n");
        }
    }
   
}

