//Program where the top-level exception is a Null Pointer Exception, and its cause is an Arithmetic Exception

//Main.java
public class chained_demo{
    public static void main(String[] args){
        try{
            try{
                int x = 10/0;
            }
            catch(ArithmeticException ex){
                NullPointerException npe = new NullPointerException("Top-level Exception: Null Pointer Exception");
                npe.initCause(ex);
                throw npe;
            }
        }
        catch(NullPointerException ex){
            System.err.println("Exception: "+ex.getMessage());
            System.err.println("Exception Cause: "+ex.getCause());
        }
    }
}
