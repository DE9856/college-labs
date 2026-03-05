//Bank Balance must maintain a minimum balance when withdrawals occur

//Custom Exception
public class InsufficientBalanceException extends Exception{
    InsufficientBalanceException(String msg){
        super(msg);
    }
}


//Main.java
import java.util.*;
public class Banking{
    final int min = 5000;
    double balance;
    Banking(double balance){
        this.balance = balance;
    }
    void withdraw(double amount) throws InsufficientBalanceException{
        if(this.balance-amount < min){
            throw new InsufficientBalanceException("Minimum balance must be maintained");
        }
        else{
            this.balance -=amount;
            System.out.println("Remaining Balance: "+this.balance);
        }
    }
    public static void main(String[] args){
        Banking b1 = new Banking(7000);
        try{
            b1.withdraw(3000);
        }
        catch(InsufficientBalanceException ex){
            System.err.println("Exception: "+ex.getMessage());
        }
        finally{
            System.out.println("Operation is done.");
        }
    }
}
