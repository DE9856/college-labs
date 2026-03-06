//Write a program to display all student names along with their marks.
import java.util.*;
public class test10{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HashMap <String, Integer> map = new HashMap <String, Integer>();
        System.out.println("Enter no. of students that you want to enter: ");
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            System.out.println("Enter name: ");
            String name = sc.next();
            System.out.println("Enter marks: ");
            int marks = sc.nextInt();
            map.put(name,marks);
        }
        for(Map.Entry <String, Integer> entry : map.entrySet())
            System.out.println(entry.getKey()+" : "+entry.getValue());
        map.clear();
        if(map.isEmpty())
            System.out.println("Map is now cleared");
    }
}
