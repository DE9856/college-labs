import java.util.*;
public class MyPoint{
    private int x,y;
  
    public MyPoint(){
        this.x = 0;
        this.y = 0;
    }
  
    public MyPoint(int x, int y){
        this.x = x;
        this.y = y;
    }
  
    public void setXY(int x, int y){
        this.x = x;
        this.y = y;
    }
  
    public int[] getXY(){
        int arr[] = new int[2];
        arr[0] = this.x;
        arr[1] = this.y;
        return arr;
    }
  
    public String toString(){
        return("("+this.x+","+this.y+")");
    }
  
    public double distance(int x, int y){
        int xDiff = this.x - x;
        int yDiff = this.y - y;
        return Math.sqrt(xDiff*xDiff + yDiff*yDiff);
    }
  
    public double distance(){
        return Math.sqrt(this.x*this.x + this.y*this.y);
    }
  
    public double distance(MyPoint another){
        int xDiff = this.x - another.x;
        int yDiff = this.y - another.y;
        return Math.sqrt(xDiff*xDiff + yDiff*yDiff);
    }
  
    public void traverse(){
        int arr[] = new int[2];
        for(int i=0;i<2;i++){
            arr[i] = this.getXY()[i];
        }
        System.out.println("("+arr[0]+","+arr[1]+")");
    }
  
    public static void main(){
        Scanner sc = new Scanner(System.in);
        MyPoint p1 = new MyPoint();
        System.out.println("Enter X and Y values for P1");
        int x = sc.nextInt();
        int y = sc.nextInt();
        p1.setXY(x,y);
        System.out.println("Enter X and Y values for P2");
        x = sc.nextInt();
        y = sc.nextInt();
        MyPoint p2 = new MyPoint(x,y);
        System.out.print("Point 1: ");
        p1.traverse();
        System.out.println("Point 2: "+p2.toString());
        System.out.println("Distance from Point 1 to origin: "+p1.distance());
        System.out.println("Distance from Point 1 to Point 2: "+p1.distance(p2));
        System.out.println("Distance from Point 1 to (2,2)"+p1.distance(2,2));
    }
}
