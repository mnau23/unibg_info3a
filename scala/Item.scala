class Item(itemId: Int, itemName: String, itemPrice: Int) extends Logger with Article {

  def log(itemName: String, description: String): Unit = println(itemName + ": " + description)

  var id: Int = itemId
  var name: String = itemName
  var price: Int = itemPrice
}