//Program 1
//Implement Binary search
import java.util.Arrays;
import java.util.Scanner;
public class P1binarysearch {
    // Function to perform binary search
    public static int binarySearch(int[] arr, int key) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                return mid; // Return the index where the key is found
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; // Return -1 if key is not found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Input the size of the array
        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();
        // Input the elements of the array
        int[] array = new int[size];
        System.out.println("Enter the elements of the array in sorted order:");
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        // Sort the array (Binary search requires sorted array)
        Arrays.sort(array);
        // Input the element to search
        System.out.print("Enter the element to search: ");
        int key = scanner.nextInt();
        scanner.close();
        // Call binarySearch function to find the index of key
        int result = binarySearch(array, key);
        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found in the array.");
        }
    }
}