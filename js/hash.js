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
    function isValidEntry(hash) {
      return table[hash] !== undefined;
    }
    function isValidKey(hash, k) {
      return table[hash][k] !== undefined;
    }
    return {
      insert: function(k, v, t) {
        var hash = hashKey(k);
        if (!isValidEntry(hash)) {
          table[hash] = {};
        }
        if (!isValidKey(hash, k)) {
          table[hash][k] = {};
        }
        table[hash][k][t] = v;
      },
      get: function(k, t) {
        var hash = hashKey(k);
        if (!isValidEntry(hash)) {
          return undefined
        }
        if (!isValidKey(hash, k)) {
          return undefined;
        }
        var times = Object.keys(table[hash][k]);
        var latestTime = -1;
        times.forEach(function(time) {
          time = Number(time);
          if (time <= t && time > latestTime) {
            latestTime = time;
          }
        });
        return table[hash][k][latestTime];
      },
      remove: function(k) {
        var hash = hashKey(k);
        if (!isValidEntry(hash)) {
          return undefined
        }
        delete table[hash][k];
      }
    }
  }

  var myHash = new HashTable(100);
  myHash.insert("mykey", "value1", 0);
  myHash.insert("mykey", "value2", 2);
  console.log(myHash.get("mykey", 0));
  console.log(myHash.get("mykey", 1));
  console.log(myHash.get("mykey", 2));
})();