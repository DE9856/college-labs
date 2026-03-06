//Replace the element at index 0 with the value 99.
import java.util.*;
public class test14{
    public static void main(){
        ArrayList <Integer> list = new ArrayList <Integer>();
        list.add(0);
        list.add(1);
        list.add(2);
        System.out.println(list);
        list.set(0,99);
        System.out.println(list);
    }
}
