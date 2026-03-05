//Thread Child Class
public class MyThread extends Thread{
    private int count;
    public MyThread(int count){
        super();
        this.count = count;
        start();
    }
    public void run(){
        for(int i=0;i<count;i++){
            System.out.println("Child Thread: "+(i+1));
            try{
                Thread.sleep(500);
            }
            catch(InterruptedException e){
                System.out.println(e);
            }
        }
    }
}


//Main.java
import java.util.Scanner;
public class MyThreadDemo{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of times you want thread to be printed: ");
        int count = sc.nextInt();
        MyThread t1 = new MyThread(count);
        for(int i=0;i<count;i++){
            System.out.println("Main Thread: "+(i+1));
            try{
                Thread.sleep(500);
            }
            catch(InterruptedException e){
                System.out.println(e);
            }
        }
    }
}
