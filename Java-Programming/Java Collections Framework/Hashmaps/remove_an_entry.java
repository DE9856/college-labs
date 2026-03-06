//Write a program to remove a student entry from the HashMap and display the updated list.

import java.util.*;
public class test5{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HashMap <String, Integer> map = new HashMap <String, Integer>();
        map.put("Deepesh",100);
        map.put("Deepesh1",99);
        map.put("Deepesh2",98);
        System.out.println("Enter the entry to remove: ");
        String str = sc.nextLine();
        if(map.containsKey(str)){ 
            System.out.println("Removed Key: "+str+"\nRemoved Value: "+map.get(str));
            map.remove(str);
        }
        else{
            System.out.println("Key is not present in the hashmap");
        }
    }
}
