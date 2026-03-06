//Write a program to check whether a given student name is present in the HashMap.
import java.util.*;
public class test3{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HashMap <String, Integer> map = new HashMap <String, Integer>();
        map.put("Deepesh", 100);
        map.put("Deepesh1", 99);
        map.put("Deepesh2", 98);
        System.out.println("Enter a key to check: ");
        String str = sc.nextLine();
        if(map.containsKey(str))
            System.out.println("Key is Present");
        else
            System.out.println("Key is not present");
    }
}
