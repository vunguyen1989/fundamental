/**
 * LSP - Liskov substitution principle example
 * 
 * @author gpcoder
 */
class Rectangle {
    private int width;
    private int height;
 
    public int calculateArea() {
        return this.width * this.height;
    }
 
    public void setWidth(int width) {
        this.width = width;
    }
 
    public void setHeight(int height) {
        this.height = height;
    }
}
 
class Square extends Rectangle {
 
    @Override
    public void setWidth(int width) {
        super.setWidth(width);
        super.setHeight(width);
    }
 
    @Override
    public void setHeight(int height) {
        super.setWidth(height);
        super.setHeight(height);
    }
}
 
class LSPExample1 {
    public static void main(String[] args){
        Rectangle rect = new Rectangle();
        rect.setWidth(5);
        rect.setHeight(10);
        System.out.println(rect.calculateArea()); // 50
 
        Square square = new Square();
        square.setWidth(5);
        square.setHeight(10);
        System.out.println(rect.calculateArea()); // 100
    }
}