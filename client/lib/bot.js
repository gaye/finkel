#!/usr/bin/env node

var Finkel = require('./gen-js/Finkel')
  , thrift = require('thrift')
  , ttypes = require('./gen-js/finkel_types');


/**
 * @constructor
 */
var Bot = function() {
};
module.exports = Bot;


Bot.prototype = {
  /**
   * Connect to some finkel service.
   * @param {string} host Host for finkel service.
   * @param {number} port Port for finkel service.
   */
  connect: function(host, port) {
    this._host = host;
    this._port = port;
    var connection = thrift.createConnection(this._host, this._port);
    this._client = thrift.createClient(Finkel, connection);
  },

  /**
   * Start running the bot.
   * @param {string} username Username for MTGO user.
   * @param {string} password Password for MTGO user.
   */
  start: function(username, password) {
    this._running = true;
    this._client.Start(username, password,
      this._takeScreenshotAndProcess.bind(this));
    this._startTime = new Date();
  },

  /**
   * Shutdown gracefully.
   */
  stop: function() {
    this._client.Stop(function() {
      this._running = false;
      if (this._timeoutId !== undefined) {
        clearTimeout(this._timeoutId);
      }
    }.bind(this));
  },

  /**
   * @type {string}
   */
  _host: undefined,

  /**
   * @type {number}
   */
  _port: undefined,

  /**
   * @type {boolean}
   */
  _running: false,

  /**
   * @type {Finkel.Client}
   */
  _client: undefined,

  /**
   * @type {boolean}
   * Whether or not there is a trade open.
   */
  _trading: false,

  /**
   * @type {Date}
   * The time when the most recent trade began.
   */
  _tradeStartDate: undefined,

  /**
   * @type {number=}
   */
  _timeoutId: undefined,

  /**
   * Number of screenshots we've taken since bringing up the bot.
   * @type {number}
   */
  _screenshotsTaken: 0,

  /**
   * When we brought up the bot.
   * @type {Date}
   */
  _startTime: undefined,

  _takeScreenshotAndProcess: function() {
    if (!this._running) {
      return;
    }

    this._screenshot = this._client.TakeScreenshot(function() {
      // Calculate perf metrics
      this._screenshotsTaken += 1;
      var duration = (new Date() - this._startTime) / 1000;
      var framerate = this._screenshotsTaken / duration;
      console.log('Framerate: ' + framerate);

      var done = this._takeScreenshotAndProcess.bind(this);
      if (this._trading) {
        // Keep trading for now.
        return this._continueTrade(done);
      }

      // Check to see if we've received a trade request.
      this._getTradeRequest(function(req) {
        if (req !== null) {
          return this._maybeAcceptTradeRequest(done);
        }

        // If we didn't receive a trade request, take this opportunity
        // to update our Marketplace post.
        this._updateListing(done);
      }.bind(this));
    }.bind(this));
  },

  /**
   * Continue processing the trade.
   * @param {Function} cb Some callback.
   */
  _continueTrade: function(cb) {
    // TODO(gareth)
    console.log('continueTrade');
    cb();
  },

  /**
   * @return {string|null} The name of the
   * @param {Function} cb Some callback to call with the name
   *     of a trader or null. 
   */
  _getTradeRequest: function(cb) {
    // TODO(gareth)
    console.log('getTradeRequest');
    cb(null);
  },

  /**
   * Compute whether or not we should accept the trade request.
   * If we're going to accept it, go ahead and do it.
   * @param {Function} cb Some callback.
   */
  _maybeAcceptTradeRequest: function(cb) {
    // TODO(gareth)
    console.log('maybeAcceptTradeRequest');
    cb();
  },

  /**
   * Update our listing in Community > Marketplace > Classifieds.
   * @param {Function} cb Some callback.
   */
  _updateListing: function(cb) {
    // TODO(gareth)
    console.log('updateListing');
    cb();
  }
};
