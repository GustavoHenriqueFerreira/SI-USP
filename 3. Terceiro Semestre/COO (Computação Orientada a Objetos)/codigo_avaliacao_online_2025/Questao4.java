import java.util.*;

public class Questao4 {

	public static <T extends Comparable<T>> Set<T> metodo(Set<T> A, Set<T> B){

		Set<T> tmp1 = new HashSet<>();
		Set<T> tmp2 = new HashSet<>();
		Set<T> resultado = new HashSet<>();

		for(T x : A) tmp1.add(x);
		for(T x : B) tmp1.add(x);
		for(T x : A) if(B.contains(x)) tmp2.add(x);
		for(T x : tmp1) if(!tmp2.contains(x)) resultado.add(x);

		return resultado;
	}	
}
