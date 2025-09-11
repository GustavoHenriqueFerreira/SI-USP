import java.util.*;

public class Questao2 {

	public static <T extends Comparable<T>> List<T> metodo(List<T> lista){

		List<T> resultado = new ArrayList<>();
		Set<T> set = new HashSet<>();

		for(T x : lista) set.add(x);
		for(T x : set) resultado.add(x);

		return resultado;
	}
}
