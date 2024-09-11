//Program 4
//Create Stack program to hold max 10 elements
import java.util.*;
public class P4stack {
    private static final int MAX_SIZE = 10;
    private int[] stackArray;
    private int top;

    public P4stack() {
        stackArray = new int[MAX_SIZE];
        top = -1;
    }
    // Function to push an element onto the stack
    public void push(int item) {
        if (top == MAX_SIZE - 1) {
            System.out.println("Stack Overflow! Cannot push element onto stack.");
            return;
        }
        stackArray[++top] = item;
        System.out.println("Pushed " + item + " onto the stack.");
    }
    // Function to pop an element from the stack
    public int pop() {
        if (top == -1) {
            System.out.println("Stack Underflow! Stack is empty.");
            return -1;
        }
        int poppedItem = stackArray[top--];
        System.out.println("Popped " + poppedItem + " from the stack.");
        return poppedItem;
    }
    // Function to display the elements of the stack
    public void display() {
        if (top == -1) {
            System.out.println("Stack is empty.");
            return;
        }
        System.out.println("Elements of the stack:");
        for (int i = top; i >= 0; i--) {
            System.out.println(stackArray[i]);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        P4stack stack = new P4stack();
        while (true) {
            System.out.println("\nStack Operations:");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Display");
            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("Enter the element to push: ");
                    int element = sc.nextInt();
                    stack.push(element);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.display();
                    break;
                default:
                    System.out.println("Invalid choice!");
                sc.close();
            }
        }
    }
}