import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by thesedays on 2017/12/30.
 */

public class Main{
    protected int x;
    Parent(int x){
        this.x = x;
    }
    public int Test(){
        if(x >= 0) return x + 10;
        return x;
    }
}

public class Child extend Parent{
    Child(int x){
        super(x);
    }
    public int Test(){
        if(x > 0) return x + 10;
    }
}
