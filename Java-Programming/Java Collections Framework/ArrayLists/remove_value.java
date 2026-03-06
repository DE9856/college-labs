//Add elements “A”, “B”, “C”, remove “B”, and print the final list.

import java.util.*;
public class test18{
    public static void main(String args[]){
        ArrayList <String> list = new ArrayList <String>();
        list.add("a");
        list.add("b");
        list.add("c");
        System.out.println(list);
        list.remove("b");
        System.out.println(list);
    }
}
