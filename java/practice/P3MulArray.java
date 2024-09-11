// Program 3 (Not given in Lab program list)
// Multiplication of 2 Matrixes (without command line arguments)
import java.util.Scanner;
public class P3MulArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i, j, k;
        int a[][] = new int[3][3];
        int b[][] = new int[3][3];
        int c[][] = new int[3][3];
        System.out.println("Enter the element of A 3X3: ");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                a[i][j] = sc.nextInt();
            }
            System.out.println();
        }
        System.out.println("Enter the element of B 3X3: ");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                b[i][j] = sc.nextInt();
            }
            System.out.println();
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                c[i][j] = 0;
                for (k = 0; k < 3; k++) {
                    c[i][j] = a[i][k] * b[k][j];
                }
            }
        }
        System.out.println("The Multiplication of the matrix is: ");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                System.out.print(c[i][j] + "\t");
            }
            System.out.println("\n");
        }
    }
}