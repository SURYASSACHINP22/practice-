// Program 7 
// resizing the height and width using Interface Concept
interface Resizable {
    void resizeWidth(int width);

    void resizeHeight(int height);
}
class Rectangle implements Resizable {
    private int width;
    private int height;

    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }
    public void resizeWidth(int width) {
        this.width = width;
        System.out.println("Resized width to: " + width);
    }
    public void resizeHeight(int height) {
        this.height = height;
        System.out.println("Resized height to: " + height);
    }

    public void display() {
        System.out.println("Rectangle - Width: " + width + ", Height: " +
                height);
    }
}

public class P7Interface {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(5, 10);
        System.out.println("Original Rectangle:");
        rectangle.display();
        // Resizing the rectangle
        rectangle.resizeWidth(8);
        rectangle.resizeHeight(15);
        System.out.println("Resized Rectangle:");
        rectangle.display();
    }
}