import java.util.*;
public class binary_search{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no. of elements in the array: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements into the array: ");
        for(int i=0;i<n;i++)
            arr[i] = sc.nextInt();
            
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
                    
        System.out.println("Enter the key to be searched: ");
        int key = sc.nextInt();
        int left =0;
        int right = n-1;
        int flag = 0;
        while(left<=right){
            int mid = (int) (left+right)/2;
            if(key==arr[mid]){
                System.out.println("The element is found in the array.");
                flag =1;
                break;
            }
            else if(key < arr[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        if(flag==0)
            System.out.println("The element is not found in the array.");
    }
}
