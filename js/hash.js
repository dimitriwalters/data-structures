(function() {
  // source: http://werxltd.com/wp/2010/05/13/javascript-implementation-of-javas-string-hashcode-method/
  function hashCode(s) {
    var hash = 0, i, chr, len;
    if (s.length == 0) return hash;
    for (i = 0, len = s.length; i < len; i++) {
      chr = s.charCodeAt(i);
      hash = ((hash << 5) - hash) + chr;
      hash |= 0;
    }
    return hash;
  };

  function HashTable(size) {
    var table = new Array(size);
    function hashKey(k) {
      return Math.abs(hashCode(k.toString())) % size;
    }
    return {
      insert: function(k, v) {
        table[hashKey(k)] = v;
      },
      get: function(k) {
        return table[hashKey(k)];
      },
      remove: function(k) {
        delete table[hashKey(k)];
      }
    }
  }

  var myHash = HashTable(100);
  myHash.insert("mykey", 2);
  console.log(myHash.get("mykey"));
  myHash.remove("mykey");
  console.log(myHash.get("mykey"));
})();