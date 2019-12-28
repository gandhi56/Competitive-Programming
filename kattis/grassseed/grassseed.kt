import java.util.Scanner

fun main(){
	val r = Scanner(System.`in`)
	var c = r.nextDouble()
	var l = r.nextInt()
	var sum: Double = 0.0
	while (l > 0){
		var w = r.nextDouble()
		var h = r.nextDouble()
		sum = sum + (w * h)
		l --
	}
	println("%.8f".format(sum*c))
}
