// Problem 3 - Closure
// Write some example(s) about how you take advantage of closure

/**
 * Private variables
 */
function createCounter() {
  let count = 0; // private variable

  return {
    increment() {
      count++;
      return count;
    },
    get() {
      return count;
    },
  };
}

const counter = createCounter();
console.log(counter.increment()); // 1
console.log(counter.increment()); // 2
console.log(counter.get()); // 2

/**
 * function factory
 */
function makeMultiplier(x) {
  return function (y) {
    return x * y; // remember x
  };
}

const double = makeMultiplier(2);
const triple = makeMultiplier(3);

console.log(double(5)); // 10
console.log(triple(5)); // 15

/**
 * @link https://github.com/Aliheym/typeorm-transactional/blob/master/src/transactions/wrap-in-transaction.ts
 * transaction like typeorm-transactional
 */
function startTransaction() {
  console.log('BEGIN TRANSACTION');
}

function commitTransaction() {
  console.log('COMMIT TRANSACTION');
}

function rollbackTransaction() {
  console.log('ROLLBACK TRANSACTION');
}

function wrapInTransaction(fn) {
  return async function (...args) {
    startTransaction();
    try {
      const result = await fn.apply(this, args);
      commitTransaction();
      return result;
    } catch (err) {
      rollbackTransaction();
      throw err;
    }
  };
}

async function saveOrder(order) {
  console.log('Saving order:', order);
  // imagine we do DB writes here
  return { ok: true };
}

const saveOrderWithTx = wrapInTransaction(saveOrder);

saveOrderWithTx({ id: 1 });
