object Test {

  // check if number contains a "7" (7,17,27,...)
  def contains7(a: Int): Int = {
    var x = a.toString()
    if(x.contains("77")) 2
    else if(x.contains("7")) 1
    else 0
  }

  // For
  def countHas7_for(a: Int, b: Int): Int = {
    var count = 0
    for(i <- List.range(a, b))
      if(contains7(i) == 2)
        count += 2
      else if (contains7(i) == 1)
        count += 1
    count
  }

  // ForEach
  def countHas7_foreach(a: Int, b: Int): Int = {
    var count = 0
    List.range(a, b).foreach(count += contains7(_))
    count
  }

  // Recursion
  def countHas7_R(a: Int, b: Int): Int = {
    var list = List.range(a, b)

    if (list.isEmpty)
      return 0;

    if (contains7(list.head) == 1)
      1 + countHas7_R(a + 1, b)
    else
      countHas7_R(a + 1, b)
  }

  // Map
  def countHas7_map(a: Int, b: Int): Int =
    List.range(a, b).map(contains7(_)).sum

  // FoldLeft
  def countHas7_foldLeft(a: Int, b: Int): Int =
    List.range(a, b).foldLeft(0)((x, y) => x + contains7(y))

  // Filter
  def countHas7_filter(a: Int, b: Int): Int =
    List.range(a, b).filter(contains7(_) == 1).size

  // HOF
  def countHas7_hof(f: (Int, Int) => Int): (Int, Int, Int) => Int = {
    def inner(a: Int, b: Int, n: Int): Int =
      List.range(a, b).filter(f(_, n) == 1).size
    inner
  }
  
  def containsN(a: Int, n: Int): Int = {
   var x = a.toString()
   if (x.contains(n.toString())) 1
   else 0
  }

  // Main
  def main(args: Array[String]) {
    println("How many 7's in 878: " + contains7(878))
    println("How many 7's in 177: " + contains7(177))

    println

    println("How many 7's in [0,100] (for): " + countHas7_for(0, 100))
    println("How many 7's in [0,40] (foreach): " + countHas7_foreach(0, 40))
    println("How many 7's in [0,30] (recursion): " + countHas7_R(0, 30))

    println

    println("How many 7's in [0,10] (map): " + countHas7_map(0, 10))
    println("How many 7's in [0,40] (foldLeft): " + countHas7_foldLeft(0, 40))
    println("How many 7's in [0,30] (filter): " + countHas7_filter(0, 30))

    println

    println("How many 7's in [0,40] (hof): " + countHas7_hof(containsN)(0, 40, 7))
  }
}