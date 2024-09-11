// Program 2
// Addition of 2 Matrixes USING COMMAND LINE ARGUMENTS
// Need to understand
public class P2AddArray {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java MatrixAddition <order_N>");
            return;
        }

        int N = Integer.parseInt(args[0]);

        if (N <= 0) {
            System.out.println("Please provide a valid positive integer for the order N.");
            return;
        }

        int[][] matrix1 = new int[N][N];
        int[][] matrix2 = new int[N][N];

        // Fill the matrices with sample values (you can modify this as needed)
        fillMatrix(matrix1, 1);
        fillMatrix(matrix2, 2);

        // Add the matrices
        int[][] resultMatrix = addMatrices(matrix1, matrix2);

        // Print the result matrix
        System.out.println("Resultant Matrix (Matrix1 + Matrix2):");
        printMatrix(resultMatrix);
    }

    private static void fillMatrix(int[][] matrix, int startValue) {
        int value = startValue;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = value++;
            }
        }
    }

    private static int[][] addMatrices(int[][] matrix1, int[][] matrix2) {
        int N = matrix1.length;
        int[][] resultMatrix = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return resultMatrix;
    }

    private static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int value : row) {
                System.out.print(value + "\t");
            }
            System.out.println();
        }
    }
}
