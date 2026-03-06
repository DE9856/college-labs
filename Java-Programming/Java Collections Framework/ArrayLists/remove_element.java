//Add 3 numbers to an ArrayList and remove the second element.
import java.util.*;
public class test13{
    public static void main(String args[]){
        ArrayList <Integer> list = new ArrayList <Integer>();
        list.add(10);
        list.add(20);
        list.add(30);
        System.out.println(list);
        list.remove(1);
        System.out.println(list);
    }
}
