#include <iostream>
#include <algorithm>

using namespace std;
void RANDOMNUMBERS(int A[], int n, int min, int max);
void InsertionSort(int A[], int n);
void SELECTIONSORT(int A[], int n);
void BUBLLESORT(int A[], int n);
void SHAKERSORT(int A[], int n);
void SHELLSORT(int A[], int n);
void BuildHeap(int A[], int n);
void Heapify(int A[], int n, int i);
void HeapSort(int A[], int n);
void merging(int low, int mid, int high);
void sort(int low, int high);

void LINEARSEARCH(int A[], int n, int num);
void BSI(int A[], int n, int num);//Binary Search iterative
int BSREC(int A[], int n, int low, int high, int num);//Binary Search Recursive
int ExponentialSearch(int A[], int n, int num);

int min(int a, int b);

void push(int stackarray[], int num);
void pop(int stackarray[]);
void showtop(int stackarray[]);

struct Node {
	int data;
	Node* next;
};
void initNode(struct Node* head, int n);
void AddNode(struct Node* head, int n);
void insertFront(struct Node** head, int n);
void dispay(struct Node* head);
struct Node* searchNode(struct Node* head, int n);

void Enqueue(int queue[], int num);
void Dequeue(int queue[]);
void Display(int queue[]);

const int n = 15;
const int mn = 15;
const int mx = 100;
int A[n];
int b[n];
const int range = mx - mn + 1;

int stack[n]; 
int top = -1;

int myqueue[n*2];
int head = -1;
int tail = -1;
void main() {
	srand(time(0));
	
	RANDOMNUMBERS(A, n, mn, mx);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Insertion";
	cout << endl;
	InsertionSort(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Selection";
	cout << endl;
	SELECTIONSORT(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Bubble";
	cout << endl;
	BUBLLESORT(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Shaker";
	cout << endl;
	SHAKERSORT(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "SHELL";
	cout << endl;
	SHELLSORT(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Heap";
	cout << endl;
	HeapSort(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "Merge Sort " << endl;
	sort(0, n-1);
	for (int i = 0; i <= n-1; i++) cout << A[i] << " ";
	cout << endl;

	cout << "LinearSearch";
	cout << endl;
	LINEARSEARCH(A, n, 21);
	cout << endl;
	cout << "Binary Search Iterative";
	cout << endl;

	BSI(A, n, 21);
	cout << endl;
	cout << "Binary Search Recursive";
	cout << endl;

	int res = BSREC(A, n, 0, n - 1, 21);
	if (res != -1) cout << 21 << " found at index " << res;
		else cout << 21 << " not found in the array";
	cout << endl;
	cout << "Exponential Search";
	cout << endl;
	int exp = ExponentialSearch(A, n, 21);
	if (exp != -1) cout << 21 << " found at index " << exp;
	else cout << 21 << " not found in the array";
	cout << endl;

	push(stack, A[n - 1]);
	cout << endl;
	showtop(stack);
	cout << endl;
	pop(stack);
	cout << endl;

	cout << "Linked list" << endl;
	struct Node* head = new Node;
	initNode(head, 10);
	AddNode(head, 20);
	AddNode(head, 30);
	dispay(head);
	cout << endl;
	searchNode(head, 30);
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		Enqueue(myqueue, A[i]);
	}
	Display(myqueue);
	Dequeue(myqueue);
	Dequeue(myqueue);
	Display(myqueue);
}
void RANDOMNUMBERS(int A[], int n, int min, int max) {
	bool used[range] = { false };
	int num = min + rand() % max;
	used[num - min] = true;
	A[0] = num;
	for (int i = 1; i < n; i++)
	{
		do
		{
			num = min + rand() % max;
		} while (used[num - min]);
		used[num - min] = true;
		A[i] = num;
	}
}

void InsertionSort(int A[], int n) {
	int key;
	int i;
	for (int j = 1; j < n; j++)
	{
		key = A[j];
		i = j - 1;
		while (i>=0 && A[i]>key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}
void SELECTIONSORT(int A[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
			if (A[j]<A[min]) min = j;
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}
void BUBLLESORT(int A[], int n) {
	bool swapped = false; 
	int i = 0;
	do
	{
		swapped = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (A[j]>A[j+1])
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				swapped = true;
			}
		}
		i++;
	} while (swapped);	
}
void SHAKERSORT(int A[], int n)
{
	int start = 0;
	int end = n-1;
	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end; i++)
		{
			if (A[i]>A[i+1])
			{
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp; 
				swapped = true;
			}
		}
		if (!swapped) break;
		end--;
		swapped = false;
		for (int i = end-1; i >= start; --i)
		{
			if (A[i] > A[i + 1])
			{
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				swapped = true;
			}
		}
		start++;
	}
}
void SHELLSORT(int A[], int n) {
	for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = A[i];
			int j;
			for (j = i; j >= interval && A[j - interval] > temp; j -= interval)
			{
				A[j] = A[j - interval];
				A[j - interval] = temp;
			}
		}
	}
}
void BuildHeap(int A[], int n) {
	for (int i = (n/2)-1; i >=0 ; i--)
		Heapify(A, n, i);
}
void Heapify(int A[], int n, int i) {
	int L = i * 2 + 1;
	int R = i * 2 + 2;
	int large = i;
	if (L < n && A[L] > A[i])
		large = L;
	if (R < n && A[R] > A[large])
		large = R;
	if (large != i) {
		int temp = A[i];
		A[i] = A[large];
		A[large] = temp;
		Heapify(A, n, large);
	}
}
void HeapSort(int A[], int n) {
	BuildHeap(A, n);
	for (int i = n - 1; i >= 0; i--)
	{
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		Heapify(A, i, 0);
	}
}
void merging(int low, int mid, int high)
{
	int l1, l2, i;
	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
	{
		if (A[l1] <= A[l2])  b[i] = A[l1++];
		else b[i] = A[l2++];
	}
	while (l1 <= mid)  b[i++] = A[l1++];
	while (l2 <= high)  b[i++] = A[l2++];
	for (i = low; i <= high; i++) A[i] = b[i];
}
void sort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		sort(low, mid);
		sort(mid + 1, high);
		merging(low, mid, high);
	}
	else { return; }
}
//Searching
void LINEARSEARCH(int A[], int n, int num) {
	int index=-1;
	for (int i = 0; i < n; i++)
	{
		if (num == A[i])
			index = i;
	}
	if (index != -1)
		cout << num << " found at index " << index;
	else cout << num << " not found in the array";
}
void BSI(int A[], int n, int num) {
	int low = 0;
	int high = n - 1;
	int index = -1;
	while (low<=high)
	{
		int mid = (low + high) / 2;
		if (num == A[mid]) {
			index = mid;
			break;
		}
		else if (num < A[mid]) high = mid - 1;
				else low = mid + 1;
	}
	if (index != -1) cout << num << " found at index " << index;
	else cout << num << " not found in the array";
}
int BSREC(int A[], int n, int low, int high, int num) {
	if (low > high) return -1;
	int mid = (low + high) / 2;
	int index = -1;
	if (num == A[mid]) return mid;
	else if (num < A[mid]) BSREC(A, n, low, mid - 1, num);
	else BSREC(A, n, mid + 1, high, num);
}
int ExponentialSearch(int A[], int n, int num) {
	if (A[0] == num) return 0;
	int bound = 1;
	while (bound <= n && A[bound] < num)
		bound *= 2;
	return BSREC(A, n, bound/2, min(n, bound), num);
}
int min(int a, int b) {
	if (a >= b) return b;
		else return a;
}

void push(int stackarray[], int num) {
	if (top >= n) {
		cout << "Stack overflow";
	}
	else {
		top++;
		stackarray[top] = num;
	}
}
void pop(int stackarray[]) {
	if (top < 0 ) {
		cout << "Stack empty";
	}
	else {
		cout << "The popped element is " << stackarray[top];
		top--;		
	}
}
void showtop(int stackarray[]) {
	if (top < 0) cout << "Stack empty";
		else cout << "The top element is " << stackarray[top];
}

void initNode(struct Node* head, int n) {
	head->data = n;
	head->next = NULL;
}
void AddNode(struct Node* head, int n) {
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	Node* cur = head;
	while (cur) {
		if (cur->next == NULL)
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}
void insertFront(struct Node **head, int n) {
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}
struct Node* searchNode(struct Node* head, int n) {
	Node* cur = head;
	while (cur) {
		if (cur->data == n)
		{
			cout << "Node " << n << " is in list" << endl; 
			return cur;
		}
		cur = cur->next;
	}
	cout << n << " is not in the list" << endl;
}
void dispay(struct Node* head) {
	Node* list = head;
	while (list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}
void Enqueue(int queue[], int num){
	if (tail == n-1)
		cout << "Queue full" << endl;
		else
		{
			if (head == -1) head = 0;
			tail++;
			queue[tail] = num;
		}
}
void Dequeue(int queue[]) {
	if (tail == -1 && head == -1) {
		cout << "Queue empty" << endl;
		return;
	}
	else {
		cout << "Dequeued item is " << queue[head] << endl;
		head++;
	}
}
void Display(int queue[]) {
	if (tail == -1 && head == -1) {
		cout << "Queue empty" << endl;
		return;
	}
	else {
		for (int i = head; i <= tail; i++)
			cout << queue[i] << " ";
	}
	cout << endl;
}
//____________________
//PRIORITY QUEUE
//____________________
//#include <iostream>
//using namespace std;
//const int tree_array_size = 20;
//int heap_size = 0;
//const int INF = 100000;
//void swap(int* a, int* b) {
//    int t;
//    t = *a;
//    *a = *b;
//    *b = t;
//}
////function to get right child of a node of a tree
//int get_right_child(int A[], int index) {
//    if ((((2 * index) + 1) < tree_array_size) && (index >= 1))
//        return (2 * index) + 1;
//    return -1;
//}
////function to get left child of a node of a tree
//int get_left_child(int A[], int index) {
//    if (((2 * index) < tree_array_size) && (index >= 1))
//        return 2 * index;
//    return -1;
//}
////function to get the parent of a node of a tree
//int get_parent(int A[], int index) {
//    if ((index > 1) && (index < tree_array_size)) {
//        return index / 2;
//    }
//    return -1;
//}
//void max_heapify(int A[], int index) {
//    int left_child_index = get_left_child(A, index);
//    int right_child_index = get_right_child(A, index);
//
//    // finding largest among index, left child and right child
//    int largest = index;
//
//    if ((left_child_index <= heap_size) && (left_child_index > 0)) {
//        if (A[left_child_index] > A[largest]) {
//            largest = left_child_index;
//        }
//    }
//
//    if ((right_child_index <= heap_size && (right_child_index > 0))) {
//        if (A[right_child_index] > A[largest]) {
//            largest = right_child_index;
//        }
//    }
//
//    if (largest != index) {
//        swap(&A[index], &A[largest]);
//        max_heapify(A, largest);
//    }
//}
//
//void build_max_heap(int A[]) {
//    int i;
//    for (i = heap_size / 2; i >= 1; i--) {
//        max_heapify(A, i);
//    }
//}
//
//int maximum(int A[]) {
//    return A[1];
//}
//
//int extract_max(int A[]) {
//    int maxm = A[1];
//    A[1] = A[heap_size];
//    heap_size--;
//    max_heapify(A, 1);
//    return maxm;
//}
//
//void increase_key(int A[], int index, int key) {
//    A[index] = key;
//    while ((index > 1) && (A[get_parent(A, index)] < A[index])) {
//        swap(&A[index], &A[get_parent(A, index)]);
//        index = get_parent(A, index);
//    }
//}
//
//void decrease_key(int A[], int index, int key) {
//    A[index] = key;
//    max_heapify(A, index);
//}
//
//void insert(int A[], int key) {
//    heap_size++;
//    A[heap_size] = -1 * INF;
//    increase_key(A, heap_size, key);
//}
//
//void print_heap(int A[]) {
//    int i;
//    for (i = 1; i <= heap_size; i++) {
//        cout << A[i] << "  ";
//    }
//    cout << endl;
//}
//int main() {
//    int A[tree_array_size];
//    insert(A, 20);
//    insert(A, 15);
//    insert(A, 8);
//    insert(A, 10);
//    insert(A, 5);
//    insert(A, 7);
//    insert(A, 6);
//    insert(A, 2);
//    insert(A, 9);
//    insert(A, 1);
//
//    print_heap(A);
//
//    increase_key(A, 5, 22);
//    print_heap(A);
//
//    decrease_key(A, 1, 13);
//    print_heap(A);
//
//    cout << maximum(A) << endl;
//    cout << extract_max(A) << endl;
//    cout << endl;
//    return 0;
//}

//BINARY SEARCH TREE
//Building a binary search tree for the sequence 10, 25, 20, 6, 21, 8, 1, 30.
//#include  <iostream>
//using namespace std;
//struct Node
//{
//	int d;
//	Node* left;
//	Node* right;
//};
//Node* first(int d);
//Node* search_insert(Node* root, int d);
//void print_tree(Node* root, int l);
////--------------------------------------------------------
//int main()
//{
//	int b[] = { 10, 25, 20, 6, 21, 8, 1, 30 };
//	Node* root = first(b[0]);
//	for (int i = 1; i < 8; i++) search_insert(root, b[i]);
//	print_tree(root, 0);
//	return 0;
//}
////-------------------------------------------------------    
//Node* first(int d)
//{
//	Node* pv = new Node;
//	pv->d = d;
//	pv->left = 0;
//	pv->right = 0;
//	return pv;
//}
////-----------------------------------------
//Node* search_insert(Node* root, int d)
//{
//	Node* pv = root, * prev;
//	bool found = false;
//	while (pv && !found)
//	{
//		prev = pv;
//		if (d == pv->d) found = true;
//		else  if (d < pv->d) pv = pv->left;
//		else                pv = pv->right;
//	}
//	if (found) return pv;
//	Node* pnew = new Node;
//	pnew->d = d;
//	pnew->left = 0;
//	pnew->right = 0;
//	if (d < prev->d)
//		prev->left = pnew;
//	else
//		prev->right = pnew;
//	return pnew;
//}
////---------------------------------------------------
//void print_tree(Node* p, int level)
//{
//	if (p)
//	{
//		print_tree(p->right, level + 1);
//		for (int i = 0; i < level; i++) cout << "  ";
//		cout << p->d << endl;
//		print_tree(p->left, level + 1);
//	}
//}
