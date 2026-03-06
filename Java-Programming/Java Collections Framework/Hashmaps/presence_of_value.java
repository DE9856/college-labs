//Write a program to check whether a given mark is present in the HashMap.

import java.util.*;
public class test4{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HashMap <String, Integer> map = new HashMap <String, Integer>();
        map.put("Deepesh",100);
        map.put("Deepesh1",99);
        map.put("Deepesh2",98);
        System.out.println("Enter a value to check: ");
        int n = sc.nextInt();
        if(map.containsValue(n))
            System.out.println("Value is present");
        else
            System.out.println("Value is not present");
    }
}
