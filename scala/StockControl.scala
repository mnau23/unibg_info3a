trait StockControl {
  def add(i: Item): Array[Item]
  def delete(id: Int): Array[Item]
  def mean_fold(): Int
  def mean_for(): Int
  def modifyPrice(id: Int, price: Int): Array[Item]
  def print(): Unit
  def search(name: String): Array[Item]
  def sum(): Int
}