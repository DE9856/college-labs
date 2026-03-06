//Create an ArrayList and remove all elements. Then check if it is empty.

import java.util.*;
public class test19{
    public static void main(String args[]){
        ArrayList <Integer> list = new ArrayList <Integer>();
        list.add(0);
        list.add(2);
        list.add(3);
        System.out.println(list);
        list.clear();
        if(list.isEmpty())
            System.out.println("List is empty");
    }
}
