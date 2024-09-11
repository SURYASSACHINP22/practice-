//Program 8
// Divide by zero exception code with try, catch, throw and finally
import java.util.Scanner;
// Custom exception class for Division By Zero
class DivisionByZeroException extends Exception {
    public DivisionByZeroException(String message) {
        super(message);
    }
}
public class P8Exception {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numerator,denominator;
        System.out.println("Enter numerator: ");
        numerator = sc.nextInt();
        System.out.println("Enter denominator: ");
        denominator = sc.nextInt();
        try {
            // Attempt division
            int result = divide(numerator, denominator);
            System.out.println("Result: " + result);
        } catch (DivisionByZeroException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Cleanup code (e.g., closing resources) goes here.");
        }
        sc.close();
    }
    // Custom method to perform division
    public static int divide(int numerator, int denominator) throws DivisionByZeroException {
        if (denominator == 0) {
            throw new DivisionByZeroException("Division by zero is not allowed.");
        }
        return numerator / denominator;
    }
}