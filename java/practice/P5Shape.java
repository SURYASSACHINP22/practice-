// Program 5
// create multiple classes to demonstrate polymorphism
class Shape {
    void draw() {
        System.out.println("Shape is drawn");
    }

    void erase() {
        System.out.println("Shape is erased");
    }
}

class Circle extends Shape {
    void draw() {
        System.out.println("Circle is drawn");
    }

    void erase() {
        System.out.println("Circle is erased");
    }
}

class Triangle extends Shape {
    void draw() {
        System.out.println("Triangle is drawn");
    }

    void erase() {
        System.out.println("Traingle is erased");
    }
}

class Square extends Shape {
    void draw() {
        System.out.println("Square is drawn");
    }

    void erase() {
        System.out.println("Square is erased");
    }
}

public class P5Shape {
    public static void main(String[] args) {
        Shape s = new Shape();
        s.draw();
        s.erase();
        Circle c = new Circle();
        c.draw();
        c.erase();
        Triangle t = new Triangle();
        t.draw();
        t.erase();
        Square sq = new Square();
        sq.draw();
        sq.erase();
    }
}