#include<iostream>
using namespace std;

struct FunctionDef {
    string name;
    int recursionCount;
    string* nestedCalls;
    int nestedCount;
    int priority;
    
    FunctionDef() {
        recursionCount = 1;
        nestedCalls = nullptr;
        nestedCount = 0;
        priority = 5;
    }
};

class Stack {
    string* arr;
    int top;
    int capacity;
    
public:
    Stack(int size) {
        capacity = size;
        arr = new string[capacity];
        top = -1;
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    bool isFull() {
        return top == capacity - 1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool push(string funcName) {
        if (isFull()) {
            return false;
        }
        arr[++top] = funcName;
        return true;
    }
    
    string pop() {
        if (isEmpty()) {
            return "";
        }
        return arr[top--];
    }
    
    void display() {
        cout << "Stack: [";
        for (int i = 0; i <= top; i++) {
            cout << arr[i];
            if (i < top) cout << ", ";
        }
        cout << "]" << endl;
    }
};

class CircularQueue {
    string* arr;
    int front, rear, size, capacity;
    
public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new string[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }
    
    ~CircularQueue() {
        delete[] arr;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool enqueue(string funcName) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = funcName;
        size++;
        return true;
    }
    
    string dequeue() {
        if (isEmpty()) {
            return "";
        }
        string result = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return result;
    }
    
    void display() {
        cout << "Waiting Queue: [";
        if (!isEmpty()) {
            int i = front;
            for (int count = 0; count < size; count++) {
                cout << arr[i];
                if (count < size - 1) cout << ", ";
                i = (i + 1) % capacity;
            }
        }
        cout << "]" << endl;
    }
};

class PriorityCircularQueue {
    string* arr;
    int* priorities;
    int front, rear, size, capacity;
    
public:
    PriorityCircularQueue(int cap) {
        capacity = cap;
        arr = new string[capacity];
        priorities = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }
    
    ~PriorityCircularQueue() {
        delete[] arr;
        delete[] priorities;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool enqueue(string funcName, int priority) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
            arr[rear] = funcName;
            priorities[rear] = priority;
        } else {
            rear = (rear + 1) % capacity;
            arr[rear] = funcName;
            priorities[rear] = priority;
        }
        size++;
        return true;
    }
    
    string dequeue() {
        if (isEmpty()) {
            return "";
        }
        
        int highestPriorityIdx = front;
        int i = front;
        for (int count = 0; count < size; count++) {
            if (priorities[i] < priorities[highestPriorityIdx]) {
                highestPriorityIdx = i;
            }
            i = (i + 1) % capacity;
        }
        
        string result = arr[highestPriorityIdx];
        
        int j = highestPriorityIdx;
        for (int count = 0; count < size - 1; count++) {
            int next = (j + 1) % capacity;
            arr[j] = arr[next];
            priorities[j] = priorities[next];
            j = next;
        }
        
        if (size == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return result;
    }
    
    void display() {
        cout << "Ready Queue: [";
        if (!isEmpty()) {
            int i = front;
            for (int count = 0; count < size; count++) {
                cout << arr[i] << "(P" << priorities[i] << ")";
                if (count < size - 1) cout << ", ";
                i = (i + 1) % capacity;
            }
        }
        cout << "]" << endl;
    }
};

bool isValidFunctionName(string name) {
    if (name.empty()) return false;
    if (!((name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z'))) {
        return false;
    }
    for (int i = 1; i < name.length(); i++) {
        char c = name[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            return false;
        }
    }
    return true;
}

int evaluateExpression(string expr) {
    int num1 = 0, num2 = 0;
    char op = ' ';
    bool foundOp = false;
    
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            op = expr[i];
            foundOp = true;
            string part2 = "";
            for (int j = i + 1; j < expr.length(); j++) {
                part2 += expr[j];
            }
            for (int k = 0; k < part2.length(); k++) {
                num2 = num2 * 10 + (part2[k] - '0');
            }
            break;
        }
        num1 = num1 * 10 + (expr[i] - '0');
    }
    
    if (!foundOp) return num1;
    
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
    if (op == '/') return num2 != 0 ? num1 / num2 : 1;
    
    return 1;
}

bool checkCircularDependency(FunctionDef* functions, int funcCount, string startFunc, string* visited, int visitedCount) {
    for (int i = 0; i < visitedCount; i++) {
        if (visited[i] == startFunc) {
            return true;
        }
    }
    
    visited[visitedCount] = startFunc;
    visitedCount++;
    
    FunctionDef* func = nullptr;
    for (int i = 0; i < funcCount; i++) {
        if (functions[i].name == startFunc) {
            func = &functions[i];
            break;
        }
    }
    
    if (func == nullptr || func->nestedCount == 0) {
        return false;
    }
    
    for (int i = 0; i < func->nestedCount; i++) {
        if (checkCircularDependency(functions, funcCount, func->nestedCalls[i], visited, visitedCount)) {
            return true;
        }
    }
    
    return false;
}

void executeFunction(string funcName, FunctionDef* functions, int funcCount, Stack& stack, int& errorOccurred) {
    FunctionDef* func = nullptr;
    for (int i = 0; i < funcCount; i++) {
        if (functions[i].name == funcName) {
            func = &functions[i];
            break;
        }
    }
    
    if (func == nullptr) return;
    
    for (int rec = 0; rec < func->recursionCount; rec++) {
        if (!stack.push(funcName)) {
            cout << "Error: Stack overflow while calling " << funcName << endl;
            errorOccurred = 1;
            return;
        }
        cout << funcName << " called" << endl;
        stack.display();
        
        for (int i = 0; i < func->nestedCount; i++) {
            executeFunction(func->nestedCalls[i], functions, funcCount, stack, errorOccurred);
            if (errorOccurred) return;
        }
    }
    
    for (int rec = 0; rec < func->recursionCount; rec++) {
        stack.pop();
        cout << funcName << " finished" << endl;
        stack.display();
    }
}

int main() {
    int N, M, S, R, W;
    cin >> N >> M >> S >> R >> W;
    cin.ignore();
    
    FunctionDef* functions = new FunctionDef[N];
    
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        
        string funcName = "";
        int idx = 0;
        while (idx < line.length() && line[idx] != '(' && line[idx] != '{' && line[idx] != ' ') {
            funcName += line[idx];
            idx++;
        }
        
        functions[i].name = funcName;
        
        if (idx < line.length() && line[idx] == '(') {
            idx++;
            string recursionStr = "";
            int parenCount = 1;
            while (idx < line.length() && parenCount > 0) {
                if (line[idx] == '(') parenCount++;
                else if (line[idx] == ')') {
                    parenCount--;
                    if (parenCount == 0) break;
                }
                recursionStr += line[idx];
                idx++;
            }
            
            if (parenCount != 0) {
                cout << "Error: Invalid parentheses in " << funcName << endl;
                continue;
            }
            
            if (recursionStr.length() > 0) {
                functions[i].recursionCount = evaluateExpression(recursionStr);
            }
            idx++;
        }
        
        if (idx < line.length() && line[idx] == '{') {
            idx++;
            string nestedStr = "";
            int braceCount = 1;
            while (idx < line.length() && braceCount > 0) {
                if (line[idx] == '{') braceCount++;
                else if (line[idx] == '}') {
                    braceCount--;
                    if (braceCount == 0) break;
                }
                nestedStr += line[idx];
                idx++;
            }
            idx++;
            
            int commaCount = 1;
            for (int j = 0; j < nestedStr.length(); j++) {
                if (nestedStr[j] == ',') commaCount++;
            }
            
            functions[i].nestedCalls = new string[commaCount];
            functions[i].nestedCount = 0;
            
            string currentNested = "";
            for (int j = 0; j < nestedStr.length(); j++) {
                if (nestedStr[j] == ',' || nestedStr[j] == ' ') {
                    if (currentNested.length() > 0) {
                        functions[i].nestedCalls[functions[i].nestedCount++] = currentNested;
                        currentNested = "";
                    }
                } else {
                    currentNested += nestedStr[j];
                }
            }
            if (currentNested.length() > 0) {
                functions[i].nestedCalls[functions[i].nestedCount++] = currentNested;
            }
        }
        
        while (idx < line.length() && line[idx] == ' ') idx++;
        if (idx < line.length()) {
            string priorityStr = "";
            while (idx < line.length() && line[idx] >= '0' && line[idx] <= '9') {
                priorityStr += line[idx];
                idx++;
            }
            if (priorityStr.length() > 0) {
                functions[i].priority = 0;
                for (int j = 0; j < priorityStr.length(); j++) {
                    functions[i].priority = functions[i].priority * 10 + (priorityStr[j] - '0');
                }
            }
        }
    }
    
    string* visited = new string[N];
    for (int i = 0; i < N; i++) {
        if (checkCircularDependency(functions, N, functions[i].name, visited, 0)) {
            cout << "Error: Circular Dependency exists" << endl;
            delete[] visited;
            for (int j = 0; j < N; j++) {
                if (functions[j].nestedCalls != nullptr) {
                    delete[] functions[j].nestedCalls;
                }
            }
            delete[] functions;
            return 0;
        }
    }
    delete[] visited;
    
    string* callSequence = new string[M];
    for (int i = 0; i < M; i++) {
        getline(cin, callSequence[i]);
    }
    
    PriorityCircularQueue readyQueue(R);
    CircularQueue waitingQueue(W);
    Stack stack(S);
    
    for (int i = 0; i < M; i++) {
        string funcName = callSequence[i];
        
        int priority = 5;
        for (int j = 0; j < N; j++) {
            if (functions[j].name == funcName) {
                priority = functions[j].priority;
                break;
            }
        }
        
        if (!readyQueue.enqueue(funcName, priority)) {
            if (!waitingQueue.enqueue(funcName)) {
                cout << "Error: All queues full, cannot schedule " << funcName << endl;
            } else {
                cout << funcName << " added to Waiting Queue" << endl;
            }
        } else {
            cout << funcName << " added to Ready Queue" << endl;
        }
        readyQueue.display();
        waitingQueue.display();
        stack.display();
    }
    
    while (!readyQueue.isEmpty()) {
        string funcToExecute = readyQueue.dequeue();
        cout << "Dequeued " << funcToExecute << " from ready queue for execution" << endl;
        readyQueue.display();
        waitingQueue.display();
        stack.display();
        
        int errorOccurred = 0;
        executeFunction(funcToExecute, functions, N, stack, errorOccurred);
        
        if (!waitingQueue.isEmpty()) {
            string movedFunc = waitingQueue.dequeue();
            int priority = 5;
            for (int j = 0; j < N; j++) {
                if (functions[j].name == movedFunc) {
                    priority = functions[j].priority;
                    break;
                }
            }
            readyQueue.enqueue(movedFunc, priority);
            cout << movedFunc << " moved from waiting queue to ready queue" << endl;
            readyQueue.display();
            waitingQueue.display();
            stack.display();
        }
    }
    
    delete[] callSequence;
    for (int i = 0; i < N; i++) {
        if (functions[i].nestedCalls != nullptr) {
            delete[] functions[i].nestedCalls;
        }
    }
    delete[] functions;
    
    return 0;
}