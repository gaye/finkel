#!/usr/bin/env node

var Bot = require('../lib/bot');


var main = function() {
  // Connect to the finkel service.
  var bot = new Bot();
  bot.connect('192.168.1.133', 9090);

  // Start MTGO and log in.
  bot.start('username', 'password');

  // Gracefully shutdown the bot when we get SIGINT.
  process.on('SIGINT', function() {
    bot.stop();
    process.exit();
  });
};


if (require.main === module) {
  main();
}
