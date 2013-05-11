#!/usr/bin/env node

var Finkel = require('../lib/gen-js/Finkel')
  , thrift = require('thrift')
  , ttypes = require('../lib/gen-js/finkel_types');


/**
 * @constructor
 * @param {string} host Host for finkel service.
 * @param {number} port Port for finkel service.
 */
var Bot = function(host, port) {
  this._host = host;
  this._port = port;
};


Bot.prototype = {
  /**
   * Connect to some finkel service.
   * @return {Finkel.Client} rpc client.
   */
  connect: function() {
    var connection = thrift.createConnection(this._host, this._port);
    return thrift.createClient(Finkel, connection);
  },

  /**
   * @type {string}
   * @private
   */
  _host: undefined,

  /**
   * @type {number}
   * @private
   */
  _port: undefined
};

var main = function() {
  var bot = new Bot('192.168.1.133', 9090);
  var client = bot.connect();
  client.start('username', 'password');
};


if (require.main === module) {
  main();
}
